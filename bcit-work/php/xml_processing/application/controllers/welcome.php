<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/welcome.php
 * 
 * Default controller for this COMP4711 Lab Solutions framework.
 * 
 * @author Kevin Csapko
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
        $this -> data['pagetitle'] = 'Kevin Csapko - Home';
        $this -> data['heading'] = 'BCIT COMP4711';
        $this -> data['subheading'] = 'Internet Software Development';
        $this -> data['timestamp'] = '22.01.2013';
        $this -> data['pagebody'] = 'home';
        $this -> render();
    }
}
