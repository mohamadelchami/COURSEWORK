<?php
require_once('common.php');

if (!UserUtils::is_logged_in())
{
  HTTPUtils::redirect('login.php');
  exit(0);
}

?>
<!DOCTYPE html>
<html>
    <head>
		<title>Register</title>
		<link rel="stylesheet" type="text/css" href="css_styles/base.css"/>
		<link rel="stylesheet" type="text/css" href="css_styles/about_page.css"/>
    </head>
    <body>
        <!--Navigation bar-->
		<header>
			<a class="logo_wrapper"href = "index.php"> 
				<img class = "logo" src="img/meshbox.png" alt="Mesh Box Logo" width="20%"> 
			</a>
			<nav> 
				<ul class = "nav_links">
					<li><a href = "index.php">Home</a></li>
					<li><a href = "private.php">My Files</a></li>
					<li><a href = "contact_us.php">Contact Us</a></li>
					<li><a href = "logout.php">Log out</a></li>
				</ul>
			</nav>
        </header>
        <!--Main Content-->
		<div class="content">
			<form method="post" enctype="multipart/form-data">
		    <label>FILE UPLOAD</label>
		    <input type="text" name="title">
		    <label>find file</label>
		    <input type="File" name="file">
		    <input type="submit" name="submit">
		</form>
		</div>

		<!--Footer-->
		<!--<footer>-->
		<!--	<h1>-->
		<!--		Hello-->
		<!--	</h1>-->
		<!--</footer>-->
    </body>
</html>