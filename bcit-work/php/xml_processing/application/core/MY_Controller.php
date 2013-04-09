<?php

/**
 * core/MY_Controller.php
 *
 * Default application controller.
 *
 * @author Kevin Csapko
 */
class Application extends CI_Controller 
{
    protected $data = array();      // Parameters for view components
    protected $id;                  // Identifier for our content

    const TICK = '<img src="/assets/images/tick.png"/>';

    protected $choices = array      // Navbar items
    ( 
        array
        (
            "href"  => "/welcome", 
            "title" => "Welcome to COMP4711", 
            "label" => "Home", "tick" => ""
        ),
        array
        (
            "href"  => "/lab03", 
            "title" => "XML document", 
            "label" => "Lab 3 (XML)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "/lab04", 
            "title" => "DTD constraints",
            "label" => "Lab 4 (DTD)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "/lab05",
            "title" => "Schema constraints", 
            "label" => "Lab 5 (Schema)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "/lab06", 
            "title" => "SimpleXML processing", 
            "label" => "Lab 6 (DOM)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "#", 
            "title" => "CodeIgniter model", 
            "label" => "Lab 7 (Model)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "#", 
            "title" => "Add XPath expressions",
            "label" => "Lab 8 (XPath)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "#", 
            "title" => "Server-side processing and data mods", 
            "label" => "Lab 9 (Server)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "#", 
            "title" => "XML-RPC client and server", 
            "label" => "Lab 10 (RPC)", 
            "tick"  => ""
        ),
        array
        (
            "href"  => "#",
            "title" => "REST and JSON",
            "label" => "Lab 11 (REST)",
            "tick"  => ""
        ),
        array
        (
            "href"  => "#",
            "title" => "REST error handling", 
            "label" => "Lab 11B (Errors)", 
            "tick"  => ""
        )
    );

    /**
     * Constructor: Establishes view parameters & loads common helpers.
     */
    function __construct() 
    {
        parent::__construct();
        
        $this->data = array();
        $this->data['title'] = 'Kevin Csapko - COMP4711';
        $this->data['errors'] = array();
    }

    /**
     * Render this page.
     */
    function render() 
    {
        $this -> data['choices'] = $this -> choices;
        $this -> data['menubar'] = $this -> parser -> parse('_menubar', 
                $this -> data, true);
        $this -> data['content'] = $this -> parser -> parse($this -> 
                data['pagebody'], $this->data, true);
        $this -> data['email'] = $this -> properties -> get('email');
        $this -> data['instructor'] = $this -> properties -> get('instructor');
        $this -> data['data'] = &$this -> data;
        $this -> parser -> parse('_template', $this -> data);
    }
}
