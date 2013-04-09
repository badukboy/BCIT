<?php

if (!defined('BASEPATH'))
{
    exit('No direct script access allowed');
}

/**
 * controllers/lab03.php
 *
 * Standard controller for the lab03 page.
 * 
 * @author Kevin Csapko
 */
class Lab03 extends Application 
{
    /**
     * Default entry point.
     */
    function index()
    {
        $this -> load -> helper('display');
        $this -> data['myxml'] = display_file('./data/populations.xml');
        $this -> data['timestamp'] = '23.01.2013';
        $this -> data['heading'] = 'LAB 3';
        $this -> data['subheading'] = 'XML';
        $this -> data['pagetitle'] = 'Kevin Csapko - Lab 3';
        $this -> data['pagebody'] = 'lab03';
        $this -> render();
    }
}

?>
