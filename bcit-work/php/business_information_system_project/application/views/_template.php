<?php

/**
 * views/_template.php
 * 
 * HTML page layout template.
 * 
 * @author Group DEF
 */

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>{pagetitle}</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">

    <link href="../assets/css/bootstrap.css" rel="stylesheet">
    <link href="../assets/css/jquery.validate.css" rel="stylesheet">
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js" type="text/javascript"></script>
    <script src="../assets/js/jquery.validate.js" type="text/javascript"></script>
    </script>
    
    <style type="text/css">
        
        /* Style overrides */
        
        body 
        {
            padding-top: 60px;
            padding-bottom: 40px;
        }
      
        .nav-collapse 
        {
            text-transform: uppercase;
            font-weight: bold;
        }
        
        .sidebar-nav 
        {
            padding: 9px 0;
        }
        
        .carousel-inner > .item > img 
        {
            height: 100%;
            width: 100%;
        }
        
    </style>
    <link href="../assets/css/bootstrap-responsive.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="../assets/css/jquery.tagsinput.css" />

    <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
    <!--[if lt IE 9]>
    <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->

    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="../assets/ico/apple-touch-icon-144-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="../assets/ico/apple-touch-icon-114-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="72x72" href="../assets/ico/apple-touch-icon-72-precomposed.png">
    <link rel="apple-touch-icon-precomposed" href="../assets/ico/apple-touch-icon-57-precomposed.png">
    <link rel="shortcut icon" href="../assets/ico/favicon.png">
</head>

<body>

    <!-- NAVIGATION -->
    <div class="navbar navbar-inverse navbar-fixed-top">
        <div class="navbar-inner">
            <div class="container-fluid">
                <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </a>
                <a class="brand" href="http://def.bcitxml.com/"><img src="../assets/img/logo_3.png" /></a>
                {menubar}
            </div>
        </div>
    </div>
    <!-- /NAVIGATION -->
    
    <!-- CONTENT -->
    <div class="container-fluid">
        {content}
    </div>
    <!-- /CONTENT -->

    <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
    <script src="../assets/js/bootstrap-transition.js"></script>
    <script src="../assets/js/bootstrap-alert.js"></script>
    <script src="../assets/js/bootstrap-modal.js"></script>
    <script src="../assets/js/bootstrap-dropdown.js"></script>
    <script src="../assets/js/bootstrap-scrollspy.js"></script>
    <script src="../assets/js/bootstrap-tab.js"></script>
    <script src="../assets/js/bootstrap-tooltip.js"></script>
    <script src="../assets/js/bootstrap-popover.js"></script>
    <script src="../assets/js/bootstrap-button.js"></script>
    <script src="../assets/js/bootstrap-collapse.js"></script>
    <script src="../assets/js/bootstrap-carousel.js"></script>
    <script src="../assets/js/bootstrap-typeahead.js"></script>
    
    <script src="../assets/js/bootstrap-datepicker.js"></script>
    <script src="../assets/js/bootstrap-select.js"></script>
    <script src="../assets/js/jquery.tagsinput.js"></script>
    <script src="../assets/js/jquery.validate.js"></script>
    <script src="../assets/js/jquery.validation.functions.js"></script>
    
    <script type="text/javascript">
        
    $(document).ready(function()
    {
        $('#datePicker').datepicker();
	$('.start-trip-out').datepicker(
        {
            style: 'inverse'
        });
        
        $('#btnremove').click(function()
        {
            $('#header_message').fadeOut('fast');
        });
              
     });
        
    !function ($) 
    {
        $(function()
        {
          $('#myCarousel').carousel(
          {
              interval: 7500
          });
        })
      }(window.jQuery)
     </script>
</body>
</html>

