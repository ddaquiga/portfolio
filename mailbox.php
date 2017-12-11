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
$un = $pw = "";

if (empty($_POST["un"]))
	$un = "";
else
	$un = test_input($_POST["un"]);

if (empty($_POST["pw"]))
	$pw = "";
else
	$pw = test_input($_POST["pw"]);

function test_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	$data = hash('sha512',$data);
	return $data;
}

$servername = "35.203.177.219";
$username = "root";
$password = "";
$dbname = "responses";

try {
	$su_conn= new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
	$su_conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	$mb_stmt = $su_conn->prepare("SELECT 1 FROM users WHERE u_name = :un AND p_word = :pw");
	$mb_stmt->bindParam(':un',$un);
	$mb_stmt->bindParam(':pw',$pw);

	$mb_stmt->execute();

	$msgs = $conn->prepare("SELECT * FROM employers");
	$msgs->execute();

}
catch(PDOException $e){
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
				<li><a href="hire-me.html"><strong>Hire Me</strong></a></li>
			</ul>
		</div>
		<div id="mainbody" class="col-sm-10">

		<?php if ($mb_stmt->rowCount() > 0) { ?>
			<h3>Messages</h3>
			<div class="panel-group">
			<?php foreach(new RecursiveArrayIterator($msgs->fetchAll()) as $k=>$v) { ?>
				<div class="panel panel-default">
					<div class="panel-heading">
						<p class="panel-title">Message from <?php echo $v["firstname"] . " " . $v["lastname"] ?></a>
						</p>
					</div>
					<div class="panel-body">
						<p>Name: <?php echo $v["firstname"] . " " . $v["lastname"] ?><br>
							Company: <?php echo $v["company"] ?><br>
							Email: <?php echo $v["email"] ?><br>
							Phone: <?php echo $v["phone"] ?><br>
							Website: <?php echo $v["website"] ?><br>
							Referred: <?php echo $v["referred"] ?><br>
							Message:<br><?php echo $v["details"] ?><br>
						</p>
					</div>
				</div>
			<?php } ?>
			</div>
		<?php } else { ?>
			<h3>Not Logged In!!!</h3>
		<?php } ?>
		</div>
	</div>
</div>
</body>
</html>

