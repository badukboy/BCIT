<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/po/welcome.php
 * 
 * Controller the Purchasing/Orders homepage.
 * 
 * @author Group DEF
 */
class Welcome extends Application 
{
    /**
     * Contacts associated with this module.
     * 
     * @var name  - The name of the student.
     * @var email - The email of the student.
     */
    protected $contacts = array
    ( 
        array
        (
            "name"  => "Gary Miao", 
            "email" => "miaocanada@hotmail.com",
        ),
        array
        (
            "name"  => "Alex Kim", 
            "email" => "alexyskim1995@gmail.com",
        ),
        array
        (
            "name"  => "Kevin Csapko", 
            "email" => "kcsapko@gmail.com",
        ),
    );
    
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
        $this -> data['contacts'] = $this -> contacts;
        $this -> data['orders'] = $this -> orders -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Orders';
        $this -> data['heading'] = 'Orders';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'Purchasing';
        
        // URLs
        $this -> data['url-index'] = '../po/welcome';    
        $this -> data['url-add'] = '../po/add'; 
        $this -> data['url-update'] = '../po/update'; 
        
        $this -> data['pagebody'] = 'po/home';
        $this -> render();
    }
}
