<?php

/**
 * @file
 *   Provides the administrative UI.
 */

/**
 * Form builder: Masked Input settings
 */
function masked_input_settings($form, &$form_state) {
  $form_state['values']['definitions'] = isset($form_state['values']['definitions']) ? $form_state['values']['definitions'] : variable_get('masked_input_definitions', array());
  $form_state['masked_input']['count'] = isset($form_state['masked_input']['count']) ? $form_state['masked_input']['count'] : count($form_state['values']['definitions']);

  $form['definition'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mask Definitions'),
  );

  $form['definition']['definitions'] = array(
    '#theme' => 'masked_input_settings_definitions',
    '#prefix' => '<div id="masked_input-definitions">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );

  for ($i = 0; $i < $form_state['masked_input']['count']; $i++) {
    $form['definition']['definitions'][$i] = _maskinput_definitions_element($i, $form_state['values']['definitions']);
  }

  $form['definition']['add_another_definition'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#submit' => array('_masked_input_definitions_add_another_submit'),
    '#ajax' => array(
      'callback' => '_masked_input_definitions_add_another_callback',
      'wrapper' => 'masked_input-definitions',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}


/**
 * Validation callback: remove invalid definitions.
 * @see masked_input_settings()
 */
function masked_input_settings_validate($form, &$form_state) {
  foreach ($form_state['values']['definitions'] as $key => $values) {
    if (empty($values['character']) || empty($values['regex'])) {
      unset($form_state['values']['definitions'][$key]);
    }
  }
}


/**
 * Submission callback: save configurations to variables table.
 * @see masked_input_settings()
 */
function masked_input_settings_submit($form, &$form_state) {
  variable_set('masked_input_definitions', $form_state['values']['definitions']);
}


/**
 * Ajax callback: return definitions element.
 * @see masked_input_settings()
 */
function _masked_input_definitions_add_another_callback($form, $form_state) {
  return $form['definition']['definitions'];
}


/**
 * Ajax submission callback: adds another definition form element.
 * @see masked_input_settings()
 */
function _masked_input_definitions_add_another_submit(&$form, &$form_state) {
  $form_state['masked_input']['count']++;
  $form_state['rebuild'] = TRUE;
  $form['definition']['definitions'][] = _maskinput_definitions_element();
}


/**
 * Helper function: builds masked input definition form element.
 */
function _maskinput_definitions_element($delta = 'new', $definitions = array()) {
  return array(
    '#type' => 'container',
    '#attributes' => array(),
    'character' => array(
      '#type' => 'textfield',
      '#size' => 1,
      '#maxlength' => 1,
      '#default_value' => isset($definitions[$delta]['character']) ? $definitions[$delta]['character'] : '',
    ),
    'regex' => array(
      '#type' => 'textfield',
      '#default_value' => isset($definitions[$delta]['regex']) ? $definitions[$delta]['regex'] : '',
    ),
    'description' => array(
      '#type' => 'textfield',
      '#default_value' => isset($definitions[$delta]['description']) ? $definitions[$delta]['description'] : '',
    ),
  );
}



/**
 * Theme callback: Masked Input Definitions settings
 * @see masked_input_settings()
 */
function theme_masked_input_settings_definitions($variables) {
  $form = $variables['form'];

  // Hard-code default mask definitions because they come with the plugin.
  $rows = _masked_input_default_definitions();

  $header = array(
    t('Character'),
    t('Regular expression'),
    t('Description'),
  );

  foreach (element_children($form) as $key) {
    $delete_key = $key . '_delete';
    $column = array();
    $column[] = array('data' => drupal_render($form[$key]['character']));
    $column[] = array('data' => drupal_render($form[$key]['regex']));
    $column[] = array('data' => drupal_render($form[$key]['description']));
    $rows[] = $column;
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);

  return $output;
}
