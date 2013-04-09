<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/lab05.php
 *
 * Standard controller for the lab05 page.
 * 
 * @author Kevin Csapko
 */
class Lab05 extends Application 
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
        $this -> data['validation'] = validate_xml_schema('./data/populations_v3.xml', './data/populations_v3.xsd');
        $this -> data['myxml'] = display_file('./data/populations_v3.xml');
        $this -> data['myschema'] = display_file('./data/populations_v3.xsd');
        
        // General placeholders
        $this -> data['timestamp'] = '05.02.2013';
        $this -> data['heading'] = 'LAB 5';
        $this -> data['subheading'] = 'Schema';
        $this -> data['pagetitle'] = 'Kevin Csapko - Lab 5';
        $this -> data['pagebody'] = 'lab05';
        
        $this -> render();
    }
}

?>
