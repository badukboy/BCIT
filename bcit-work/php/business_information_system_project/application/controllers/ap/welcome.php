<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/ap/welcome.php
 * 
 * Controller the Accounts Payable/Vendors homepage.
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
            "name"  => "Dominic Odorisio", 
            "email" => "dominicodorisio@gmail.com",
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
        $this -> data['vendors'] = $this -> vendors -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Vendors';
        $this -> data['heading'] = 'Vendors';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'Accounts Payable';
        
        // URLs
        $this -> data['url-index'] = '../ap/welcome';    
        $this -> data['url-add'] = '../ap/add'; 
        $this -> data['url-update'] = '../ap/update'; 
        
        $this -> data['pagebody'] = 'ap/home';
        $this -> render();
    }
}
