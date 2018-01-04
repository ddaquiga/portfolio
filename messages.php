<!DOCTYPE html>

<html lang="en">
<head>
	<title>Messages</title>
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
	$u_name = $p_word = "";

	if (empty($_POST["u_name"])) $u_name = "";
	else $u_name = test_input($_POST["u_name"]);

	if (empty($_POST["p_word"])) $p_word = "";
	else $p_word = test_input($_POST["p_word"]);

	function test_input($data) {
		$data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		$data = hash('sha512',$data);
		return $data;
	}
	$server = 'mysql:unix_socket=/cloudsql/ddaquigan-188900:us-central1:portfolio-instance;dbname=responses';
	$user = 'root';
	$pass = '';

	try{
		$conn = new PDO($server, $user, $pass);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$logged = $conn->prepare("SELECT 1 from users WHERE u_name = :u_name AND p_word = :p_word");
		$logged->bindParam(':u_name',$u_name);
		$logged->bindParam(':p_word',$p_word);
		$logged->execute();

		if ($logged->rowCount() > 0){
			$stmt = $conn->prepare("SELECT * FROM employers");
			$stmt->execute();
			$stmt->setFetchMode(PDO::FETCH_ASSOC);
		}
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
			<?php if ($logged->rowCount() <= 0) echo "<h3>Not Logged In</h3>";
			else { ?>
				<h3>Messages</h3>
				<?php if ($stmt->rowCount() <= 0) { ?>
					<p>No Messages</p>
				<?php } else { ?>
					<div class="panel-group">
						<?php foreach(new RecursiveArrayIterator($stmt->fetchAll()) as $k=>$v) { ?>
							<div class="panel panel-default">
								<div class="panel-heading">
									<p class="panel-title">Message from <?php echo $v["firstname"] . " " . $v["lastname"] . " - " . $v["posttime"]; ?></p>
								</div>
								<div class="panel-body">
									<p>ID: <?php echo $v["ID"]; ?></p>
									<p>Company: <?php echo $v["company"]; ?></p>
									<p>Email: <?php echo $v["email"]; ?></p>
									<p>Phone: <?php echo $v["phone"]; ?></p>
									<p>Website: <?php echo $v["website"]; ?></p>
									<p>Details:<br> <?php echo $v["details"]; ?></p>
								</div>
							</div>
						<?php } ?>
					</div>
				<?php }
			} ?>				
		</div>
	</div>
</div>
</body>
</html>