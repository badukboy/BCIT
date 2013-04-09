<?php

if (!defined('BASEPATH'))
    exit('No direct script access allowed');

/**
 * models/populations.php
 * 
 * Model for population XML data.
 * 
 * @author Kevin Csapko
 */
class Populations extends CI_Model
{
    var $district;
    
    /**
     * Constructor.
     */
    function __construct() 
    {
        parent::__construct();     
        $this -> district = simplexml_load_file('./data/populations_v4.xml');
    }
    
    /**
     * Builds a visual table based on XML data.
     * 
     * @return results - An array of rows to will up the table with.
     */
    function buildTable()
    {
        $results = array();
        
        foreach($this -> district -> children() as $record)
        {   
            $row = array
            (
                'sgc' => (string)$record -> area['sgc'],
                'name' => (string)$record -> area['name'],
                'type' => (string)$record['type'],
                'p2006' => (int)$record -> xpath('//area/population[@year="2006"]'),
                'p2007' => (int)$record -> xpath('//area/population[@year="2007"]'),
                'p2008' => (int)$record -> area -> population,
                'p2009' => (int)$record -> area -> population,
                'p2010' => (int)$record -> area -> population,
                'p2011' => (int)$record -> area -> population,
                'p2012' => (int)$record -> area -> population,
                'change' => (int)$record -> area -> population,
            );
            
            $results[] = $row;
        }
        
        return $results;
    }
}
