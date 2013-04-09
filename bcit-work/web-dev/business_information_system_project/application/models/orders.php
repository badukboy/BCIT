<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/orders.php
 * 
 * Standard model for the Orders table.
 *
 * @author Group DEF
 */
class Orders extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('orders', 'id');
    }

 }
 