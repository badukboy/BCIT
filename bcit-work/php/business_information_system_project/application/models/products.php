<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/products.php
 * 
 * Standard model for the Products table.
 *
 * @author Group DEF
 */
class Products extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('products', 'id');
    }

 }
 