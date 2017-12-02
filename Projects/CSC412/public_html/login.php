<!DOCTYPE html>
<html lang="en">
	<head>
		<meta http-equiv="content-type" content="text/html; charset=UTF-8">
		<meta charset="utf-8">
		<title>ddaquiga-Login</title>
		<meta name="generator" content="Bootply" />
		<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
		<link href="css/bootstrap.min.css" rel="stylesheet">
		<!--[if lt IE 9]>
			<script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		<link href="css/styles.css" rel="stylesheet">
	</head>
	<body>
<!-- Wrap all page content here -->
<div id="wrap" class="">
    <!-- Fixed navbar -->
    <div class="navbar navbar-default navbar-fixed-top">
        <div class="container">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse"> <span class="icon-bar"></span>
 <span class="icon-bar"></span>
 <span class="icon-bar"></span>

                </button> <p class="navbar-brand">Darrel Daquigan - CSC 412</p>

            </div>
            <div class="collapse navbar-collapse">
                <ul class="nav navbar-nav">
                    <li><a href="index.html" class="">Login</a>
                    </li>
                    <li class="dropdown"> <a href="" class="dropdown-toggle" data-toggle="dropdown">About <b class="caret"></b></a>

                        <ul class="dropdown-menu">
                            <li><a href="about_discGolf.html" class="">Disc Golf</a>
                            </li>
                            <li><a href="about_chess.html" class="">Chess</a>
                            </li>
                         
                		</ul>
                	</li>
                  	<li class="dropdown"> <a href="" class="dropdown-toggle" data-toggle="dropdown">Current <b class="caret"></b></a>

                        <ul class="dropdown-menu">
                            <li><a href="current_academic.html" class="">Academics</a>
                            </li>
                            <li><a href="current_professional.html" class="">Professional</a>
                            </li>
                         
                		</ul>
                	</li>
                  	<li><a href="contact.html" class="">Contact</a>
                    </li>
                  	<li class="active"><a href="login.html" class="">Login</a>
                  	</li>
                  	
                </ul>
            </div>
            <!--/.nav-collapse -->
        </div>
    </div>
    <!-- Begin page content -->
    <div class="container">
        <div class="page-header">
             <h1 class="">Login</h1>
        </div>
        <div>
            <?php
                $myfile = fopen("logHistory.txt","r+") or die("Unable to open file!");
                fwrite($myfile,$_POST["name"]."\n");
                fclose($myfile);
            ?>
            <p>Thank you for visiting my site, <?php echo $_POST["name"];?>.</p>
            
            <h1>Other visitors:</h1>
                <?php 
                    $myfile2 = fopen("logHistory.txt","r");
                    while(!feof($myfile2)){
                        echo fgets($myfile2) . "<br>";
                    }
                    fclose($myfile2);
                ?>
        </div>
        <div>
            <a href="index.html">Continue to the homepage</a>
        </div>
            
    </div>
</div>
<div id="footer" class="">
    <div class="container">
        <p class="text-muted credit">Courtesy of San Francisco State University Computer Science Department</p>
    </div>
</div>
	<!-- script references -->
		<script src="//ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
		<script src="js/bootstrap.min.js"></script>
		<script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.2.1/angular.min.js"></script>
	</body>
</html>