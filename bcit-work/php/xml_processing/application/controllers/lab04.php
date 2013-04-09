<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/lab04.php
 *
 * Standard controller for the lab04 page.
 * 
 * @author Kevin Csapko
 */
class Lab04 extends Application 
{
    /**
     * Default entry point.
     */
    function index()
    {
        // Load helpers
        $this -> load -> helper('display');
        $this -> load -> helper('common');
        
        // XML validation and display
        $this -> data['validation'] = validate_xml('./data/populations_v2.xml');
        $this -> data['myxml'] = display_file('./data/populations_v2.xml');
        $this -> data['mydtd'] = display_file('./data/populations_v2.dtd');
        
        // General placeholders
        $this -> data['timestamp'] = '29.01.2013';
        $this -> data['heading'] = 'LAB 4';
        $this -> data['subheading'] = 'DTD';
        $this -> data['pagetitle'] = 'Kevin Csapko - Lab 4';
        $this -> data['pagebody'] = 'lab04';
        
        $this -> render();
    }
}

?>
