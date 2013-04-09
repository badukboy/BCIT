<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/lab06.php
 *
 * Standard controller for the lab06 page.
 * 
 * @author Kevin Csapko
 */
class Lab06 extends Application 
{
    /**
     * Default entry point.
     */
    function index()
    {
        // Load helpers
        $this -> load -> helper('display');
        $this -> load -> helper('common');
        $this -> load -> model('populations');
        
        // Table placeholders
        $this -> data['report_title'] = "Populations Data";
        $this -> data['row'] = $this -> populations -> buildTable();
        echo var_dump($this -> data['row']);
        
        // General placeholders
        $this -> data['timestamp'] = '12.02.2013';
        $this -> data['heading'] = 'LAB 6';
        $this -> data['subheading'] = 'DOM';
        $this -> data['pagetitle'] = 'Kevin Csapko - Lab 6';
        $this -> data['pagebody'] = 'lab06';
        
        $this -> render();
    }
}

?>
