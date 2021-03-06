<!DOCTYPE html>

<html lang="en">
<head>
	<title>Thank You</title>
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<link rel="stylesheet" href="site.css">
	<link rel="icon" type="image/ico" href="logos/favicon.ico">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
	<script src="animations.js"></script>
</head>

<body id="override-bootstrap">
<?php
	$firstname = $lastname = $company = $email = $phone = $website = $details = "";

	if (empty($_POST["firstname"])) $firstname = "";
	else $firstname = test_input($_POST["firstname"]);

	if (empty($_POST["lastname"])) $lastname = "";
	else $lastname = test_input($_POST["lastname"]);

	if (empty($_POST["company"])) $company = "";
	else $company = test_input($_POST["company"]);

	if (empty($_POST["email"])) $email = "";
	else $email = test_input($_POST["email"]);

	if (empty($_POST["phone"])) $phone = "";
	else $phone = test_input($_POST["phone"]);

	if (empty($_POST["website"])) $website = "";
	else $website = test_input($_POST["website"]);

	if (empty($_POST["details"])) $details = "";
	else $details = test_input($_POST["details"]);

	function test_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}

	$server = 'mysql:unix_socket=/cloudsql/ddaquigan-188900:us-central1:portfolio-instance;dbname=responses';
	$user = 'root';
	$pass = '';

	try{
		$conn = new PDO($server, $user, $pass);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $conn->prepare("INSERT INTO employers (firstname, lastname, company, email, phone, website, details, posttime) VALUES (:firstname, :lastname, :company, :email, :phone, :website, :details, CONVERT_TZ(NOW(),'+00:00','-08:00'))");
		$stmt->bindParam(':firstname', $firstname);
		$stmt->bindParam(':lastname', $lastname);
		$stmt->bindParam(':company', $company);
		$stmt->bindParam(':email', $email);
		$stmt->bindParam(':phone', $phone);
		$stmt->bindParam(':website', $website);
		$stmt->bindParam(':details', nl2br($details));
		$stmt->execute();
	}
	catch(PDOException $e)
	{
		echo "Connection failed: " . $e->getMessage();
	}
?>
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
			<li><a class="nav-item" href="hire-me.html">Hire Me</a></li>
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
				<li class="active"><a href="hire-me.html"><strong>Hire Me</strong></a></li>
			</ul>
		</div>
		<div id="mainbody" class="col-sm-10">
			<h3>Thank You</h3>
			<h2>I will contact you as soon as I can</h2>
		</div>
	</div>
</div>
</body>
</html>