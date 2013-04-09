<?php

/**
 * views/ar/_add_form.php
 * 
 * Generic form allows for adding a data entry to the corresponding database.
 * 
 * @author Group DEF
 */

$this -> load -> helper('form');
    
echo form_open('/add/post');

echo form_input(array
(
    'name' => 'id',
    'value' => '',
    'placeholder' => 'ID',
    'style' => 'display: block;',
    'id' => 'id'
));

echo form_input(array
(
    'name' => 'surname',
    'value' => '',
    'placeholder' => 'Surname',
    'style' => 'display: block;',
    'id' => 'surname'
));

echo form_input(array
(
    'name' => 'firstname',
    'value' => '',
    'placeholder' => 'First name',
    'style' => 'display: block;',
    'id' => 'firstname'
));

$options = array(
    'status' => 'Status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Add Customer', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>

