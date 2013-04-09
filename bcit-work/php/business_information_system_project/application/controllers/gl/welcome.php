<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/gl/welcome.php
 * 
 * Controller the General Ledger/Accounts homepage.
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
            "name"  => "Colin Wadge", 
            "email" => "colin.garbage@gmail.com",
        ),
        array
        (
            "name"  => "Vincent Thai", 
            "email" => "vincent__thai@hotmail.com",
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
        $this -> data['accounts'] = $this -> accounts -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Accounts';
        $this -> data['heading'] = 'Accounts';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'General Ledger';
        
        // URLs
        $this -> data['url-index'] = '../gl/welcome';    
        $this -> data['url-add'] = '../gl/add'; 
        $this -> data['url-update'] = '../gl/update';
        
        $this -> data['pagebody'] = 'gl/home';
        $this -> render();
    }
}
