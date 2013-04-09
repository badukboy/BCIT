<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * models/accounts.php
 * 
 * Standard model for the Accounts table.
 *
 * @author Group DEF
 */
class Accounts extends _Mymodel {

    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
        $this -> setTable('accounts', 'id');
    }

 }
 