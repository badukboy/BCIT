<?php

/**
 * views/_template.php
 * 
 * HTML page layout template.
 * 
 * @author Kevin Csapko
 */

?>

<html>
<head>
    <title>{pagetitle}</title>
    <meta HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">
    <meta NAME="Keywords" CONTENT="BCIT COMP4711 XML Codeigniter">
    <link rel="stylesheet" type="text/css" href="/assets/style.css"/>
</head>
<body>
    <div class="wrapper">
        
        <div id="header">
            <!-- <div class="title">{title}</div> -->
        </div>
        <div id="navbar">
            {menubar}
        </div>
        <div id="content">
            {content}
        </div>
        <div id="footer">
            <p>Kevin Csapko &nbsp; &nbsp; A00800403 &nbsp; &nbsp; Set 4G &nbsp; &nbsp; | &nbsp; &nbsp; <a href="#">Top</a></p>
        </div>
        
    </div>
</body>
</html>
