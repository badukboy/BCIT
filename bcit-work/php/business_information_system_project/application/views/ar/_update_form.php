<?php

/**
 * views/ar/_update_form.php
 * 
 * Generic form allows for updating a data entry to the corresponding database.
 * 
 * @author Group DEF
 */

$this -> load -> helper('form');
    
echo form_open('/update/post');

echo form_input(array
(
    'name' => 'id',
    'value' => '',
    'placeholder' => 'ID of customer to update',
    'style' => 'display: block;',
    'id' => 'id'
));

echo form_input(array
(
    'name' => 'surname',
    'value' => '',
    'placeholder' => 'New surname',
    'style' => 'display: block;',
    'id' => 'surname'
));

echo form_input(array
(
    'name' => 'firstname',
    'value' => '',
    'placeholder' => 'New first name',
    'style' => 'display: block;',
    'id' => 'firstname'
));

$options = array(
    'status' => 'New status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Update Customer', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>

