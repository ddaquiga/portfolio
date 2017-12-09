<!DOCTYPE html>

<html lang="en">
<head>
	<title>Darrel Daquigan</title>
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<link rel="stylesheet" href="site.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
	<script src="animations.js"></script>
</head>

<body id="override-bootstrap">

<nav class="navbar navbar-default">
	<div class="container-fluid">
		<div class="navbar-header">
			<a class="navbar-brand" href="index.html"><big><b>Darrel Daquigan</b></big></a>
		</div>
		<ul class="nav navbar-nav">
			<li><a class="nav-item" href="projects.html">Portfolio</a></li>
			<li><a class="nav-item" href="resume.html">Resume</a></li>
			<li><a class="nav-item" href="about-me.html">About Me</a></li>
			<li><a class="nav-item" href="contact.html">Contact</a></li>
			<li class="active"><a class="nav-item" href="hire-me.html">Hire Me</a></li>
		</ul>
	</div>
</nav>
<div class="container-fluid">
	<div class="row">
		<div id="sidebar" class="col-sm-2">
			<ul class="nav nav-pills nav-stacked">
				<li><a href="index.html"><strong>Home</strong></a></li>
				<li><a href="projects.html"><strong>Portfolio</strong></a></li>
				<li><a href="resume.html"><strong>Resume</strong></a></li>
				<li><a href="about-me.html"><strong>About Me</strong></a></li>
				<li><a href="contact.html"><strong>Contact</strong></a></li>
				<li class="active"><a href="hire-me.php"><strong>Hire Me</strong></a></li>
			</ul>
		</div>
		<div id="mainbody" class="col-sm-10">
			<h3>Hire Darrel</h3>
			<p>***Please fill out form or explore my website to learn more***</p>
			<form action="thankyou.php" method="post">
				First Name*:<br>
				<input type="text" name="firstname" required><br><br>
				Last Name*:<br>
				<input type="text" name="lastname" required><br><br>
				Company:<br>
				<input type="text" name="company"><br><br>
				Email Address*:<br>
				<input type="text" name="email" required><br><br>
				Telephone Number:<br>
				<input type="text" name="phone"><br><br>
				Your Website:<br>
				<input type="text" name="website"><br><br>
				How did you hear about www.ddaquigan.com?<br>
				<input type="text" name="referred"><br><br>
				Project Details:<br>
				<input type="text" name="details"><br><br>
				<input type="submit" value="Submit">
			</form>
		</div>
	</div>
</div>
</body>
</html>
