<?php

/**
 * views/po/home.php
 * 
 * Orders homepage/index view. Displays the table as is.
 * 
 * @author Group DEF
 */

?>

<div class="row-fluid">
    <div class="span2">
        <div class="well sidebar-nav">
            <ul class="nav nav-list">
                <h4>TOOLS</h4>
                <hr />
                <li class="nav-header">{table-name}</li>
                <li class="active"><a href="{url-index}"><i class="icon-home"></i> Index</a></li>
                <li><a href="{url-add}"><i class="icon-plus"></i> Add</a></li>
                <li><a href="{url-update}"><i class="icon-edit"></i> Update</a></li>
                <li class="nav-header">Contact</li>
                {contacts}
                    <li><a href="mailto:{email}"><i class="icon-envelope"></i> {name}</a></li>
                {/contacts}
            </ul>
        </div>
    </div>
    <div class="span10">
        <h1>{heading}</h1> <h4>&raquo; {subheading}</h4>
        <hr />
        <table class="table table-striped">
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Vendor ID</th>
                    <th>Description</th>
                    <th>Date</th>
                    <th>Status</th>
                </tr>
            </thead>
            <tbody>
                {orders}
                <tr>
                    <td>{id}</td>
                    <td>{vendor}</td>
                    <td>{description}</td>
                    <td>{date}</td>
                    <td>{status}</td>
                </tr>
                {/orders}
            </tbody>
        </table>
    </div>
</div>

<hr>

<!-- FOOTER -->
{footer}
<!-- /FOOTER -->