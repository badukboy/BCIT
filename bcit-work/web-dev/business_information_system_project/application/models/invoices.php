<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/invoices.php
 * 
 * Standard model for the Vendors table.
 *
 * @author Group DEF
 */
class Invoices extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('invoices', 'id');
    }

 }
 