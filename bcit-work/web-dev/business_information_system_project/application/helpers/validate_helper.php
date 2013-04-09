<?php

if (!defined('APPPATH'))
{
    exit('No direct script access allowed');
}

/**
 * helpers/validate_helper.php
 * 
 * Generic helper functions to validate input fields.
 * 
 * @author Group DEF
 */

/**
 * Validates an ID number to ensure it is a 3-digit sequence of numbers.
 * 
 * @param type $id_input - the ID input
 * @return true if the ID is valid, false if the phone number is invalid
 */
function validate_id($id_input)
{
    if(preg_match("/^[0-9]{3}$/", $id_input))
    {
        return true;
    }
}

function validate_status($status)
{
    if($status == "A" || $status == "D")
    {
        return true;
    }
    
    return false;
}

/**
 * Validates a phone number input to ensure it is in a generic form of three
 * numbers, followed by a dash, followed by another three numbers, followed by
 * a dash, followed by another four number.
 * 
 * @param type $number - the phone number input
 * @return true if the phone number is valid, false if the phone number is not
 * valid
 */
function validate_phone($number)
{
    if(preg_match("/^[0-9]{3}-[0-9]{3}-[0-9]{4}$/", $number))
    {
        return true;
    }
}

?>
