<?php

/**
 * views/home.php
 * 
 * Home page view - information about the development environment.
 * 
 * @author Group DEF
 */

?>

<div class="row-fluid">
    <div class="span2">
        {team}
    </div>
    <div class="span10">
            <div id="myCarousel" class="carousel slide">
      <div class="carousel-inner">
        <div class="item active">
          <img src="../assets/img/banner_1.png" alt="">
          <div class="container">
            <div class="carousel-caption">
              <h2>D-E-F, we definite</h2>
              <p class="lead">We sell home appliances. What, did you expect nuclear warheads or stolen top secret military aircraft? We're just your everyday average startup, and we can assure you that there is absolutely everything to be suspicious about.</p>
            </div>
          </div>
        </div>
        <div class="item">
          <img src="../assets/img/banner_2.png" alt="">
          <div class="container">
            <div class="carousel-caption">
              <h2>Holla holla, get dolla</h2>
              <p class="lead">We are your classic stereotypical bunch of capitalist pigs. We want your money, and you probably want to give it to us, so why not just start buying stuff now?</p>
            </div>
          </div>
        </div>
        <div class="item">
          <img src="../assets/img/banner_3.png" alt="">
          <div class="container">
            <div class="carousel-caption">
              <h2>Please just buy this crap</h2>
              <p class="lead">It's not like you're going to use it a month from now. Just buy it because we all know you are all hyped up about it now.</p>
            </div>
          </div>
        </div>
      </div>
    </div>
        <div class="row-fluid" style="text-align: justify;">
            <div class="span4">
                <h3>Accounts</h3>
                <p>Access our general ledger, which contains information about all of our accounts and their respective account numbers. Developed by Colin Wadge and Vincent Thai. Normally this information should be kept away from the public, but really, we're just that nice.</p>
                <p><a class="btn" href="/gl">View accounts &raquo;</a></p>
            </div>
            <div class="span4">
                <h3>Vendors</h3>
                <p>Information in regards to our accounts payable. Developed, maintained, and constantly recalculated to ensure utmost accuracy to the nearest cent by our highly trained accounting wizard, Dominic Odorisio.</p>
                <p><a class="btn" href="/ap">View vendors &raquo;</a></p>
            </div>
            <div class="span4">
                <h3>Customers</h3>
                <p>Dollar bills owed to Group DEF by its clients and customers is displayed in our accounts receivable page for public humiliation, and is maintained by Mike McNally. If you don't pay up, you'll probably be getting a knock on the door soon.</p>
                <p><a class="btn" href="/ar">View customers &raquo;</a></p>
            </div>
        </div>
        <div class="row-fluid" style="text-align: justify;">
            <div class="span4">
                <h3>Orders</h3>
                <p>The purchasing department, managed by Gary Miao and Alex Kim, keeps track of order details as they come in. Speaking of orders, why don't you stop reading this and just order something today?</p>
                <p><a class="btn" href="/po">View orders &raquo;</a></p>
            </div>
            <div class="span4">
                <h3>Invoices</h3>
                <p>An invoice or bill is a commercial document issued by a seller to the buyer, indicating the products, quantities, and agreed prices for products or services the seller has provided the buyer. Order entry and invoices are brought to you by none other than Harry Maynard and Spencer Such.</p>
                <p><a class="btn" href="/oe">View invoices &raquo;</a></p>
            </div>
            <div class="span4">
                <h3>Products</h3>
                <p>Shakeel Norali and Nal Mgana keep track of our inventory of products. If anything goes missing, it would most likely be the result of an act of sabotage from another company.</p>
                <p><a class="btn" href="/ic">View products &raquo;</a></p>
            </div>
        </div>
    </div>
</div>

<hr>

<!-- FOOTER -->
{footer}
<!-- /FOOTER -->