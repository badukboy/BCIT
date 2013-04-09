<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/customers.php
 * 
 * Standard model for the Customers table.
 *
 * @author Group DEF
 */
class Customers extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('customers', 'id');
    }

 }
 