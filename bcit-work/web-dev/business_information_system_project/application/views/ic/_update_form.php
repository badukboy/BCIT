<?php

/**
 * views/ic/_update_form.php
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
    'placeholder' => 'ID of product to update',
    'style' => 'display: block;',
    'id' => 'id'
));

echo form_input(array
(
    'name' => 'productname',
    'value' => '',
    'placeholder' => 'New product name',
    'style' => 'display: block;',
    'id' => 'productname'
));

echo form_input(array
(
    'name' => 'quantityonhand',
    'value' => '',
    'placeholder' => 'New quantity on hand',
    'style' => 'display: block;',
    'id' => 'quantityonhand'
));

echo form_input(array
(
    'name' => 'reorderpoint',
    'value' => '',
    'placeholder' => 'New reorder point',
    'style' => 'display: block;',
    'id' => 'reorderpoint'
));

echo form_input(array
(
    'name' => 'reorderquantity',
    'value' => '',
    'placeholder' => 'New redorder quantity',
    'style' => 'display: block;',
    'id' => 'reorderquantity'
));

echo form_input(array
(
    'name' => 'supplieraccountno',
    'value' => '',
    'placeholder' => 'New preferred supplier account no.',
    'style' => 'display: block;',
    'id' => 'supplieraccountno'
));

$options = array(
    'status' => 'New status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Update Product', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>

