<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/vendors.php
 * 
 * Standard model for the Vendors table.
 *
 * @author Group DEF
 */
class Vendors extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('vendors', 'id');
    }

 }
 