<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/oe/add.php
 * 
 * Controller the Order Entry/Invoices add item page.
 * 
 * @author Group DEF
 */
class Add extends Application 
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
        // Data values associated with a single data entry
        $record = array
        (
            'id' => '',
            'customer' => '',
            'description' => '',
            'date' => '',
            'status' => ''
        );
        
        $this -> data = array_merge($this -> data, $record);
        
        $this -> data['contacts'] = $this -> contacts;
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Invoices';
        $this -> data['heading'] = 'Invoices';
        $this -> data['subheading'] = 'Add';
        $this -> data['table-name'] = 'Order Entry';
        
        // URLs
        $this -> data['url-index'] = '../oe/welcome';    
        $this -> data['url-add'] = '../oe/add'; 
        $this -> data['url-update'] = '../oe/update'; 
        
        // Form data
        $this -> data['add_form'] = $this -> parser -> parse('oe/_add_form',
                $this -> data, true);
        
        $this -> data['pagebody'] = 'oe/add';
        $this -> render();
    }
    
    /**
     * Handling a post.
     */
    function post()
    {
        // Call to neccessary variables and helpers
        $new_id = $_POST['id'];
        $this -> load -> helper('validate_helper');
        
        // Check to see if the ID already exists
        if($this -> invoices -> get($new_id) != null)
        {
            $this -> data['errors'][] = 'ID already in use.';
        }
        
        // Check to see if the ID is invalid
        if(!validate_id($_POST['id']))
        {
            $this -> data['errors'][] = 'Invalid ID.';
        }
        
        // Check to see if the status is invalid.
        if(!validate_status($_POST['status']))
        {
            $this -> data['errors'][] = 'Invalid status.';
        }
        
        // If more than 0 errors exist, adding entry fails, error produced
        if(count($this -> data['errors']) > 0)
        {
           redirect('../add');
            //$this -> index();
        }
        else
        {
            $this -> invoices -> add($_POST);
            redirect('../');      
        }
    }
}
