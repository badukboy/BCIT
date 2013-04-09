<?php

if (!defined('APPPATH'))
{
    exit('No direct script access allowed');
}

/**
 * helpers/display_helper.php
 *
 * Useful functions to help display content.
 *
 * @author Kevin Csapko
 */

/**
 * Retrieve the contents of a file and prepare it for browser display. Example 
 * usage (inside a controller method):
 * 
 * $this->load->helper('display');
 * $data['contents'] = display_file('./data/flights.dtd');
 * $this->load->view('whatever',$data);
 *
 * @param string $filename - Name of the file whose contents you want to 
 *                           display, relative to the document root
 * @return string          - The appropriately encoded text string containing 
 *                           that file's contents
 */
function display_file($filename) 
{
    // Get "our" object instance reference, because this is just a function
    $CI = & get_instance();
    
    // Load the CI file helper
    $CI -> load -> helper('file');
    
    // Retrieve the requested file content
    $stuff = read_file($filename);
    
    // Convert any HTML entities
    $stuff = htmlentities($stuff);
    
    // Bracket the result inside *code* and *pre* HTML elements
    $stuff = '<code><pre>' . $stuff . '</pre></code>';

    return $stuff;
}
