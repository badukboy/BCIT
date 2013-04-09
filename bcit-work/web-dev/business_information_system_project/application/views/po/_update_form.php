<?php

/**
 * views/oe/_update_form.php
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
    'placeholder' => 'ID of order to update',
    'style' => 'display: block;',
    'id' => 'id'
));

echo form_input(array
(
    'name' => 'vendor',
    'value' => '',
    'placeholder' => 'New vendor ID',
    'style' => 'display: block;',
    'id' => 'vendor'
));

echo form_input(array
(
    'name' => 'description',
    'value' => '',
    'placeholder' => 'New description',
    'style' => 'display: block;',
    'id' => 'description'
));

echo form_input(array
(
    'name' => 'date',
    'value' => '',
    'placeholder' => 'New date',
    'style' => 'display: block;',
    'id' => 'datePicker',
    'class' => 'date-picker'
));

$options = array(
    'status' => 'New status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Update Order', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>

