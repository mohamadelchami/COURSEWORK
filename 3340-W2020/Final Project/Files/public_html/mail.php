<?php
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$aboutinq = $_POST['About'];
$message = $_POST['subject'];
$formcontent="From: $firstname $lastname \nInquiry: $aboutinq\n Message: $message";
$recipient = "hadeal25@gmail.com";
$subject = "Contact Form";
mail($recipient, $subject, $formcontent) or die("Error!");
echo "Thank You!" . " -" . "<a href='contact_us.php' style='text-decoration:none;color:#ff0099;'> Return</a>";
?>