# Masked Input

This module allows a user to more easily enter fixed width input where you
would like them to enter the data in a certain format (dates, phone numbers,
etc).

Sometimes you need the user to input data in a particular format like a Social
Security Number or a standard phone number. By masking input of a particular
textbox, you can change its behavior so that it accepts input only according to
specified format, e.g. a masked phone number input box will only allow 10 digits
of the phone number to pass through and won’t accept any other input.

The Masked Input module is a wrapper for the [Masked Input jQuery Plugin](https://github.com/digitalBush/jquery.maskedinput)
by Josh Bush.

## Installation

Install this module using the official Backdrop CMS instructions at
<https://backdropcms.org/guide/modules>. The module includes the Masked Input
jQuery plugin.

Enable the modules from the Administration >> Modules page.

## Usage

The Masked Input module is used in Content Type design when adding a Text field.
From the Widget selection, choose Masked Input and click Save. After defining
the maximum length and saving again, you will arrive at a page for more detail
on your new field. Define the mask in the Mask field.

Example: Go to the Manage Fields form for Basic Page (Or create a new content
type, and go to Manage Fields).

1. Add a new field called Phone Number.
2. From the Select A Field Type pulldown, select Text.
3. From the Select A Widget pulldown, select Masked Input.
4. Click Save.
5. On the next page, accept the default field length, and click Save.
6. On the next page, scroll down until you see a field labelled Mask.
7. In the Mask field, type
  `(999) 999-9999`
8. Save settings
9. Save the content type

When you create a new node of type you created or altered, the Phone Number
field will have the following: `(___) ___-____`

The field will only accept three numerals inside the parentheses, three numerals
before the dash, and four numerals after the dash. It will not accept letters,
only numbers. That is because of the mask we created in step 7.

## Advanced

You can create new Mask Defenitions at Administration » Configuration » User
interface » Masked Input (`admin/config/user-interface/masked_input`).

## Todo

The jquery.maskedinput library is archived. Might need a replacement:

* <https://github.com/RobinHerbots/Inputmask> (used in Drupal 9 Webform, updated
  2023)
* or <https://igorescobar.github.io/jQuery-Mask-Plugin/> (last updated 2020)

Also, might want to expand the module to behave more like
<https://www.drupal.org/project/mask>.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

## Maintainers

* [herbdool](https://github.com/herbdool)
* Seeking co-maintainers.

## Credits

Ported to Backdrop by [herbdool](https://github.com/herbdool).

This module is based on a part of the Masked Input module for Drupal,
originally written and maintained by a large number of contributors, including:

* <https://www.drupal.org/u/phthlaap>
* <https://www.drupal.org/u/twooten>
* <https://www.drupal.org/u/gajanannehul>
* <https://www.drupal.org/u/helior>

The jquery.maskedinput library was created by [digitalBush](https://github.com/digitalBush).
