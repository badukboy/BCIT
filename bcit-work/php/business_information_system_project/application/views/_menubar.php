<?php

/**
 * views/_menubar.php
 * 
 * This is an internal view fragment that builds the top-level overall
 * navigation.
 * 
 * @author Group DEF
 */

?>

<div class="nav-collapse collapse">
    <ul class="nav pull-right">
        {choices}
        <li><a href="{href}"><i class="{icon}"></i> {label}</a></li>
        {/choices}
    </ul>
</div>
