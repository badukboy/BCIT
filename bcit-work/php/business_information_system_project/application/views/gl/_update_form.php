<?php

/**
 * views/gl/_update_form.php
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
    'placeholder' => 'ID of account to update',
    'style' => 'display: block;',
    'id' => 'id'
));

echo form_input(array
(
    'name' => 'accountname',
    'value' => '',
    'placeholder' => 'New account name',
    'style' => 'display: block;',
    'id' => 'accountname'
));

$options = array(
    'status' => 'New status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Update Account', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>

