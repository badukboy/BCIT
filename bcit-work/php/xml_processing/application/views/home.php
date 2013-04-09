<?php

/**
 * views/home.php
 * 
 * Home page view - information about the development environment.
 * 
 * @author Kevin Csapko
 */

?>

<div>
    <h1><span class="oranged">{heading}</span> &#8211; {subheading} <span class="timestamp">{timestamp}</span></h1>
    <hr />
    My development environment:
    <ul>
        <li>Operating system: <a href="http://windows.microsoft.com/en-US/windows7/products/home" target="_blank">Windows 7</a></li>
        <li>AMP distribution: <a href="http://www.apachefriends.org/en/xampp.html" target="_blank">XAMPP 1.8.1</a></li>
        <li>Apache: <a href="http://httpd.apache.org" target="_blank">2.4.3</a></li>
        <li>PHP: <a href="http://www.php.net/" target="_blank">5.4.7</a></li>
         <li>Web document base: /xampp/htdocs</li>
        <li>XAMPP configuration files: /xampp/apache/config</li>
        <li>XAMPP error logs: /xampp/apache/logs</li>
    </ul>
</div>
