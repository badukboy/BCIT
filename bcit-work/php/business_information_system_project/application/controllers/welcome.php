<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/welcome.php
 * 
 * Default controller for the homepage of the DEF Group.
 * 
 * @author Group DEF
 */
class Welcome extends Application 
{
    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();
    }

    /**
     * Default entry point.
     */
    function index() 
    {
        $this -> data['pagetitle'] = 'Group DEF | Home';
        $this -> data['pagebody'] = 'home';
        $this -> render();
    }
}
