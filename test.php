<!DOCTYPE html>

<html lang="en">
<head>
	<title>Darrel Daquigan</title>
	<meta comment="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>

<body>
<?php

$firstnameErr = $lastnameErr = $emailErr = "";
$name = $email = $comment = $website = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if (empty($_POST["firstname"])) {
		$firstnameErr = "First name is required";
	}
	else {
		$firstname = test_input($_POST["firstname"]);
	}
	if (empty($_POST["lastname"])) {
		$lastnameErr = "Last name is required";
	}
	else {
		$lastname = test_input($_POST["lastname"]);
	}
	if (empty($_POST["comment"])) {
		$commentErr = "Comment is required";
	}
	else {
		$comment = test_input($_POST["comment"]);
	}

	if (empty($_POST["email"])) {
		$emailErr = "Email is required";
	}
	else {
		$email = test_input($_POST["email"]);
	}

	if (empty($_POST["website"])) {
		$website = "";
	}
	else {
		$website = test_input($_POST["website"]);
	}

	if (empty($_POST["comment"])) {
		$comment = "";
	}
	else {
		$comment = test_input($_POST["comment"]);
	}

	$servername = "35.203.177.219";
	$username = "root";
	$password = "";
	$dbname = "myDB";

	$conn = new mysqli($servername, $username, $password, $dbname) or die("Connection failed: " . $conn->connect_error);
	$firstname = $conn->real_escape_string($_POST['firstname']);
	$lastname = $conn->real_escape_string($_POST['lastname']);
	$email = $conn->real_escape_string($_POST['email']);

	$query = "insert into myguests (firstname, lastname, email) values('" . $firstname . "','" . $lastname . "','" . $email . "')";
	if ($conn->query($query)){
		$sql = "SELECT id, firstname, lastname, email FROM MyGuests";
		$result = $conn->query($sql);

		if ($result->num_rows > 0) {
		    // output data of each row
		    while($row = $result->fetch_assoc()) {
		        echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. " - Email: " .$row["email"]."<br>";
		    }
		} else {
		    echo "0 results";
		}
	}
	else{
		die("Couldn't enter data: ".$conn->error);
	}
}

function test_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return $data;
}


?>
<form action="<?php echo $_SERVER["PHP_SELF"];?>" method="post">
	First Name: <input type="text" name="firstname">
	<span class="error">* <?php echo $firstnameErr;?></span>
	<br><br>

	Last Name: <input type="text" name="lastname">
	<span class="error">* <?php echo $lastnameErr;?></span>
	<br><br>
	
	E-mail: <input type="text" name="email"><br>
	<input type="submit">
</form>

</body>
</html>

