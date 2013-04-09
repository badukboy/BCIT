<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/ic/welcome.php
 * 
 * Controller the Inventory Control/Products homepage.
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
            "name"  => "Shakeel Norali", 
            "email" => "ogshakog@hotmail.com",
        ),
        array
        (
            "name"  => "Nalumbikya Mgana", 
            "email" => "ciel073@gmail.com",
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
        $this -> data['products'] = $this -> products -> getAll_array();
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Products';
        $this -> data['heading'] = 'Products';
        $this -> data['subheading'] = 'Index';
        $this -> data['table-name'] = 'Inventory Control';
        
        // URLs
        $this -> data['url-index'] = '../ic/welcome';    
        $this -> data['url-add'] = '../ic/add'; 
        $this -> data['url-update'] = '../ic/update'; 
        
        $this -> data['pagebody'] = 'ic/home';
        $this -> render();
    }
}
