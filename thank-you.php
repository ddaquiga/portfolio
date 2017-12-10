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

<?php 
$firstname = $lastname = $company = $email = $phone = $website = $referred = $details = "";

if (empty($_POST["firstname"]))
	$firstname = "";
else
	$firstname = test_input($_POST["firstname"]);

if (empty($_POST["lastname"]))
	$lastname = "";
else
	$lastname = test_input($_POST["lastname"]);

if (empty($_POST["company"]))
	$company = "";
else
	$company = test_input($_POST["company"]);

if (empty($_POST["email"]))
	$email = "";
else
	$email = test_input($_POST["email"]);

if (empty($_POST["phone"]))
	$phone = "";
else
	$phone = test_input($_POST["phone"]);

if (empty($_POST["website"]))
	$website = "";
else
	$website = test_input($_POST["website"]);

if (empty($_POST["referred"]))
	$referred = "";
else
	$referred = test_input($_POST["referred"]);

if (empty($_POST["details"]))
	$details = "";
else
	$details = test_input($_POST["details"]);

$servername = "ddaquigan-188101:us-west1:portfolio-instance";
$username = "root";
$password = "";
$dbname = "responses";

$conn = new mysqli($servername, $username, $password, $dbname) or die("Connection failed: " . $conn->connect_error);

$query = "INSERT INTO employers (firstname, lastname, company, email, phone, website, referred, details) values ('" . $firstname . "','" . $lastname . "','" . $company . "','" . $email . "','" . $phone . "','" . $website . "','" . $referred . "','" . $details . "')";
if ($conn->query($query)){
	$sql = "SELECT ID, firstname, lastname, company, email, phone, website, referred, details from employers";
	$result = $conn->query($sql);
}
else
	die("Couldn't enter data: " . $conn->error);


function test_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
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

			<?php if ($result->num_rows > 0) { ?>
				<table class="table table-responsive table-hover">
					<thead>
						<tr>
							<th>ID</th>
							<th>firstname</th>
							<th>lastname</th>
							<th>company</th>
							<th>email</th>
							<th>phone</th>
							<th>website</th>
							<th>referred</th>
							<th>details</th>
						</tr>
					</thead>
					<tbody>
				<?php while($row = $result->fetch_assoc()) { ?>
					<tr>
						<td><?php echo $row["ID"] ?></td>
						<td><?php echo $row["firstname"] ?></td>
						<td><?php echo $row["lastname"] ?></td>
						<td><?php echo $row["company"] ?></td>
						<td><?php echo $row["email"] ?></td>
						<td><?php echo $row["phone"] ?></td>
						<td><?php echo $row["website"] ?></td>
						<td><?php echo $row["referred"] ?></td>
						<td><?php echo $row["details"] ?></td>
					</tr>
				<?php } ?>
					</tbody>
				</table>
			<?php }  else { ?>
				<p>0 results</p>
			<?php } ?>
		</div>
	</div>
</div>
</body>
</html>

