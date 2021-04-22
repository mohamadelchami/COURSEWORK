<?php
require_once('common.php');

$VALID_REDIRECT = 'private.php';
$INVALID_REDIRECT = 'register.php';
$REDIRECT = $INVALID_REDIRECT;

// check if the POST array format is as expected...
$db = new DBUser();
if (!$db->check_user_pass($_POST['uname'], $_POST['pass'])) {
    $db->insert($_POST['uname'], $_POST['pass']);
    UserUtils::log_in_user($_POST['uname']);
    $REDIRECT = $VALID_REDIRECT;
} else {
    UserUtils::log_out_user();
}

// redirect the user to an appropriate page...
HTTPUtils::redirect($REDIRECT);