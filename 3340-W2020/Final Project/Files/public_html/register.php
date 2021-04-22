<?php?>
<!DOCTYPE html>
<html>
    <head>
		<title>Register</title>
		<link rel="stylesheet" type="text/css" href="css_styles/base.css"/>
        <link rel="stylesheet" type="text/css" href="css_styles/register_page.css"/>
        <link href="https://fonts.googleapis.com/css?family=Karla|Rubik&display=swap" rel="stylesheet">
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
					<li><a href = "index.php">My Files</a></li>
					<li><a href = "contact_us.php">Contact Us</a></li>
					<li><a href = "login.php">Log in</a></li>
				</ul>
			</nav>
        </header>
        <!--Main Content-->
		<div class="content">
			<div class="container">
                <div class="get_started">
                    <img src="img/meshbox-white.svg" alt="Mesh box logo" width="10%">
                    <h2>Get Started</h2>
                    <p>					We offer a new and innovative way to share files. By bring millions of users together world wide, <br> we create a database of files and give each user 
					the opportunity to add and benefit from everyone's knowledge.</p>
                </div>
                <div class="form_register">
                    <h2>Create Account</h2>
                    <div class="social_media_signup">
                        <img src="img/facebook_icon.svg" alt="facebook icon">
                        <img src="img/google_icon.svg" alt="google icon">
                        <img src="img/linkedin_icon.svg" alt="linkedin icon">
                    </div>
                    <p>or use your email for registration:</p>
				    <form class="form_register" action="processregister.php" method="post">
					    <!--<label for="username">username</label><br> -->
					    <input id="username" type="text" name="uname" placeholder="Username"><br>
					    <!--<label for="password">password</label><br> -->
                        <input id="password" type="password" name="pass" placeholder="Password"><br>
					    <button id="register_button" type="submit" name="register-submit">SIGN UP</button>
				    </form>
                </div>
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