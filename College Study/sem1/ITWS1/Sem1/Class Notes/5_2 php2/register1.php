<?php
    /***************************************************************
		register1.php
		Implements a registration form for Groups.
		Redirects user to groups1.php upon error.
     ***************************************************************/

    // validate submission
    if (empty($_POST["name"]) || empty($_POST["gender"]) || empty($_POST["state"]))
    {
        header("Location: http://localhost/groups/groups1.php");
        exit;
    }

?>

<!DOCTYPE html>

<html>
  <head>
    <title>Groups</title>
  </head>
  <body>
    You are registered!  (Well, not really.)
  </body>
</html>
