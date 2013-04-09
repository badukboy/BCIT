<?php

/**
 * core/MY_Controller.php
 *
 * Default application controller.
 *
 * @author Group DEF
 */
class Application extends CI_Controller 
{
    protected $data = array();      // Parameters for view components
    protected $id;                  // Identifier for our content

    protected $choices = array      // Navbar items
    ( 
        array
        (
            "href"  => "/welcome", 
            "title" => "COMP4711 | Group DEF",
            "icon"  => "icon-home icon-white",
            "label" => "Home",
        ),
        array
        (
            "href"  => "/gl", 
            "title" => "COMP4711 | Accounts", 
            "icon"  => "icon-user icon-white",
            "label" => "Accounts",
        ),
        array
        (
            "href"  => "/ap", 
            "title" => "COMP4711 | Vendors", 
            "icon"  => "icon-tag icon-white",
            "label" => "Vendors",
        ),
        array
        (
            "href"  => "/ar", 
            "title" => "COMP4711 | Customers", 
            "icon"  => "icon-globe icon-white",
            "label" => "Customers",
        ),
        array
        (
            "href"  => "/po", 
            "title" => "COMP4711 | Orders", 
            "icon"  => "icon-plane icon-white",
            "label" => "Orders",
        ),
        array
        (
            "href"  => "/oe", 
            "title" => "COMP4711 | Invoices", 
            "icon"  => "icon-barcode icon-white",
            "label" => "Invoices",
        ),
        array
        (
            "href"  => "/ic", 
            "title" => "COMP4711 | Products",
            "icon"  => "icon-shopping-cart icon-white",
            "label" => "Products",
        ),
    );

    /**
     * Constructor: Establishes view parameters & loads common helpers.
     */
    function __construct() 
    {
        parent::__construct();
        
        $this->data = array();
        $this->data['title'] = 'COMP4711 - Group DEF';
        $this->data['errors'] = array();
    }

    /**
     * Render this page.
     */
    function render() 
    {
        // Navigation item choices data
        $this -> data['choices'] = $this -> choices;
        
        // Navigation bar template
        $this -> data['menubar'] = $this -> parser -> parse('_menubar', 
                $this -> data, true);
        
        // Team list template
        $this -> data['team'] = $this -> parser -> parse('_team',
                $this -> data, true);
        
        // Tool list template
        $this -> data['tools'] = $this -> parser -> parse('_tools',
                $this -> data, true);
        
        // Page content collection
        $this -> data['content'] = $this -> parser -> parse($this -> 
                data['pagebody'], $this -> data, true);
        
        // Footer template
        $this -> data['footer'] = $this -> parser -> parse('_footer',
                $this -> data, true);
        
        // Default website template
        $this -> parser -> parse('_template', $this -> data);
        
        $this -> data['add_form'] = $this -> parser -> parse('ar/_add_form',
                $this -> data, true);
    }
}
