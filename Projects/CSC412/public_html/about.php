<!DOCTYPE html>
<html lang="en">
	<head>
		<meta http-equiv="content-type" content="text/html; charset=UTF-8">
		<meta charset="utf-8">
		<title>ddaquiga-About</title>
		<meta name="generator" content="Bootply" />
		<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
		<link href="css/bootstrap.min.css" rel="stylesheet">
		<!--[if lt IE 9]>
			<script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		<link href="css/styles.css" rel="stylesheet">
                <script src="//code.jquery.com/jquery-1.10.2.js"></script>
                <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
                <script>    
                    $(document).ready(function(){
                        $(".dgContent").hide();
                        $(".dgHeader").click(function(){
                            $(".dgContent").toggle("blind");
                        });
                        $(".chessContent").hide();
                        $(".chessHeader").click(function(){
                            $(".chessContent").toggle("blind");
                        });
                    });
                </script>
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
                    <li><a href="index.html" class="">Home</a>
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
                  	<li><a href="login.html" class="">Login</a>
                  	</li>
                  	
                </ul>
            </div>
            <!--/.nav-collapse -->
        </div>
    </div>
    <!-- Begin page content -->
    <div class="container">
        <div class="page-header">
             <h1 class="">About Me</h1>
        </div><div id="general">
                <p>I am a junior at SFSU, transferring from CCSF. This is a 
                    practice website for my Computer Science 412 Advanced 
                    Software Lab for Spring 2015.</p>
            </div>
            <div  id="hobbies">
                <h2>Hobbies</h2>
                <p>click for more information</p>
                <div id="discgolf">
                    <div class="dgHeader">
                        <h3 style="color: #FFF; background-color: #003692;">Disc Golf</h3>
                    </div>
                    <div class="dgContent" style="padding-bottom: 150px;">
                        <p style="float: left;">
                            <img src="https://s-media-cache-ak0.pinimg.com/originals/3f/05/c8/3f05c86feed050930d98d15f659dcb8c.jpg"
                             alt="Disc Golf" style="width:280px">
                        </p>
                        <p>I've been playing disc golf for almost a year up in the 
                            course in Golden Gate Park, my favorite place in the 
                            world. Disc golf is like ball golf but with discs. 
                            My favorite disc is my Champion Beast.
                        </p>
                    </div>
                  
                </div>
                <div id="chess">
                    <div class="chessHeader">
                        <h4 style="color: #FFF; background-color: #003692;">Chess</h4>
                    </div>
                    <div class="chessContent">
                        <p style="float:left;">
                            <img src="http://upload.wikimedia.org/wikipedia/commons/6/6f/ChessSet.jpg"
                                     alt="chess" style="width:280px">
                        </p>
                        <p>I've been playing chess for two years, mostly on the 
                            mobile chess.com app. Challenge Dral0905 any time.
                        </p>
                    </div>
                </div>
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