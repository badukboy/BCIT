<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/ar/update.php
 * 
 * Controller the Accounts Receivable/Customers update item page.
 * 
 * @author Group DEF
 */
class Update extends Application 
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
        
        // Titles and headings
        $this -> data['pagetitle'] = 'Group DEF | Customers';
        $this -> data['heading'] = 'Customers';
        $this -> data['subheading'] = 'Update';
        $this -> data['table-name'] = 'Accounts Receivable';
        
        // URLs
        $this -> data['url-index'] = '../ar/welcome';    
        $this -> data['url-add'] = '../ar/add'; 
        $this -> data['url-update'] = '../ar/update';
        
        // Form data
        $this -> data['update_form'] = $this -> parser -> parse('ar/_update_form',
                $this -> data, true);
        
        $this -> data['pagebody'] = 'ar/update';
        $this -> render();
    }
    
    /**
     * Handling a post.
     */
    function post()
    {
        $new_id = $_POST['id'];
        $this -> load -> helper('validate_helper');
        
        // Check to see if the ID already exists
        if($this -> customers -> get($new_id) == null)
        {
            $this -> data['errors'][] = 'ID does not exist.';
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
           redirect('../update');
           //$this -> index();
        }
        else
        {
            $this -> customers -> update($_POST);
            redirect('../');      
        }
    }
}
