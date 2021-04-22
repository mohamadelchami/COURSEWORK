<?php
require_once('common.php');

$VALID_REDIRECT='index.php';
$INVALID_REDIRECT='index.php';
$REDIRECT=$INVALID_REDIRECT;

header('Content-Type: text/plain');
try
{
  $db = new DBUser();
  $db->admin_create_all_structures();
  $REDIRECT=$VALID_REDIRECT;
}
catch (Exception $e)
{
}

// redirect the user to an appropriate page...
HTTPUtils::redirect($REDIRECT);
?>