<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/oe/welcome.php
 * 
 * Controller the Order Entry/Invoices homepage.
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
            "name"  => "Harry Maynard", 
            "email" => "maynard321@hotmail.com",
        ),
        array
        (
            "name"  => "Spencer Such", 
            "email" => "s-man_360@hotmail.com",
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
        $this -> data['invoices'] = $this -> invoices -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Invoices';
        $this -> data['heading'] = 'Invoices';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'Order Entry';
        
        // URLs
        $this -> data['url-index'] = '../oe/welcome';    
        $this -> data['url-add'] = '../oe/add'; 
        $this -> data['url-update'] = '../oe/update'; 
        
        $this -> data['pagebody'] = 'oe/home';
        $this -> render();
    }
}
