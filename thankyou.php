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
{% if results %}
				<h3>Employers Entries</h3>
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
					{% for row in results %}
						<tr>
							<td>{{ row.firstname }}</td>
							<td>{{ row.lastname }}</td>
							<td>{{ row.company }}</td>
							<td>{{ row.email }}</td>
							<td>{{ row.phone }}</td>
							<td>{{ row.website }}</td>
							<td>{{ row.referred }}</td>
							<td>{{ row.details }}</td>
						</tr>
					{% endfor %}
					</tbody>
				</table>
			{% endif %}
</div>
</body>
</html>

