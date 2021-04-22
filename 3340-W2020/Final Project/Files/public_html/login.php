<?php
require_once('common.php');

?>
<!DOCTYPE html>
<html>
	<head>
		<title>MeshFile </title>
		<link rel="stylesheet" type="text/css" href="css_styles/base.css"/>
		<link rel="stylesheet" type="text/css" href="css_styles/home_page.css"/>
		<link href="https://fonts.googleapis.com/css?family=Karla|Rubik&display=swap" rel="stylesheet">
	</head>
	<body>
		<!--Navigation bar-->
		<header>
			<a class="logo_wrapper" href = "index.php"> 
				<img class = "logo" src="img/meshbox.png" alt="Mesh Box Logo" width="20%"> 
			</a>
			<nav> 
				<ul class = "nav_links">
					<li><a href = "index.php">Home</a></li>
					<li><a href = "index.php">My Files</a></li>
					<li><a href = "contact_us.php">Contact Us</a></li>
					<li><a href='login.php'>Log in</a></li>
				</ul>
			</nav>
		</header>
		<!--Main Content-->
		<div class="content">
			<div class="content_message">
				<h1>Share, all in once place</h1>
				<br>
				<p>					We offer a new and innovative way to share files. By bring millions of users together world wide, <br> we create a database of files and give each user 
					the opportunity to add and benefit from everyone's knowledge.</p>
			</div>
			<div class="content_login">
				<h2>User Login</h2>
				<form class="login_form" action="processlogin.php" method="post">
					<label for="username">username</label><br> 
					<input id="username" type="text" name="uname" placeholder="Username"><br>
					<label for="password">password</label><br> 
					<input id="password" type="password" name="pass" placeholder="Password"><br>
					<button id="login_button" type="submit">LOGIN</button>
					<a href="register.php">Forgot password?</a>
				</form>
				<a id="register_link" href="register.php">Create your account &rarr;</a>
			</div>
		</div>
		<!--Footer-->
		<footer>
			<h1>
				Hello
			</h1>
		</footer>
	</body>
</html>