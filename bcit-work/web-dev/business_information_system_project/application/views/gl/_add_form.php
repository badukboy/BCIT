<?php

/**
 * views/gl/_add_form.php
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
    'name' => 'accountname',
    'value' => '',
    'placeholder' => 'Name',
    'style' => 'display: block;',
    'id' => 'accountname'
));

$options = array(
    'status' => 'Status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Add Account', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>
