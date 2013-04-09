<?php

/**
 * views/ic/_add_form.php
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
    'name' => 'productname',
    'value' => '',
    'placeholder' => 'Product name',
    'style' => 'display: block;',
    'id' => 'productname'
));

echo form_input(array
(
    'name' => 'quantityonhand',
    'value' => '',
    'placeholder' => 'Quantity on hand',
    'style' => 'display: block;',
    'id' => 'quantityonhand'
));

echo form_input(array
(
    'name' => 'reorderpoint',
    'value' => '',
    'placeholder' => 'Reorder point',
    'style' => 'display: block;',
    'id' => 'reorderpoint'
));

echo form_input(array
(
    'name' => 'reorderquantity',
    'value' => '',
    'placeholder' => 'Redorder quantity',
    'style' => 'display: block;',
    'id' => 'reorderquantity'
));

echo form_input(array
(
    'name' => 'supplieraccountno',
    'value' => '',
    'placeholder' => 'Preferred supplier account no.',
    'style' => 'display: block;',
    'id' => 'supplieraccountno'
));

$options = array(
    'status' => 'Status',
    'A'  => 'Active',
    'D'    => 'Disabled',
);

echo form_dropdown('status', $options, 'status', "style='display: block;'");

echo form_submit('','Add Product', "class='btn'");
echo form_reset('', 'Clear Fields', "class='btn'");

echo form_close();
   
?>
