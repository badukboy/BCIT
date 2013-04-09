<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/ar/welcome.php
 * 
 * Controller the Accounts Receivable/Customers homepage.
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
            "name"  => "Mike McNally", 
            "email" => "mikejamemcnally@gmail.com",
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
        $this -> data['customers'] = $this -> customers -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Customers';
        $this -> data['heading'] = 'Customers';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'Accounts Receivable';
        
        // URLs
        $this -> data['url-index'] = '../ar/welcome';    
        $this -> data['url-add'] = '../ar/add'; 
        $this -> data['url-update'] = '../ar/update'; 
        
        $this -> data['pagebody'] = 'ar/home';
        $this -> render();
    }
}
