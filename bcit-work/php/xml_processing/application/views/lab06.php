<?php

/**
 * views/lab06.php
 * 
 * COMP4711 Lab 6 view - XML processing.
 * 
 * @author Kevin Csapko
 */

?>
<div>
    <h1><span class="oranged">{heading}</span> &#8211; {subheading} <span class="timestamp">{timestamp}</span></h1>
    <hr />
    <div class="panel">
        <div>
            <h1>{report_title}</h1>
            <table>
                <tr>
                    <th>SGC</th>
                    <th>Name</th>
                    <th>Area Type</th>
                    <th>2006</th>
                    <th>2007</th>
                    <th>2008</th>
                    <th>2009</th>
                    <th>2010</th>
                    <th>2011</th>
                    <th>2012</th>
                    <th>% Change</th>
                </tr>
                {row}
                <tr>
                    <td>{sgc}</td>
                    <td>{name}</td>
                    <td>{type}</td>
                    <td>{p2006}</td>
                    <td>{p2007}</td>
                    <td>{p2008}</td>
                    <td>{p2009}</td>
                    <td>{p2010}</td>
                    <td>{p2011}</td>
                    <td>{p2012}</td>
                    <td>{change}</td>
                </tr>
                {/row}
            </table>
        </div>
    </div>
</div>