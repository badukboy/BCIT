<?php

/**
 * views/_menubar.php
 * 
 * This is an internal view fragment that builds the left side menu bar.
 * 
 * @author Kevin Csapko
 */

?>

<ul>
    {choices}
    <li><a href="{href}" title="{title}">{label}</a>{tick}</li>
    {/choices}
</ul>
