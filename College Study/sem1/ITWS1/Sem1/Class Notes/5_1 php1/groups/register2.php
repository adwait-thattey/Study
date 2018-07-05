<?php
    /***********************************************************************
     * register2.php
     * Implements a registration form for Groups. Informs user of any errors.
     **********************************************************************/
?>

<!DOCTYPE html>

<html>
  <head>
    <title>Groups</title>
  </head>
  <body>
    <?php if (empty($_POST["name"]) || empty($_POST["gender"]) || empty($_POST["state"])): ?>
      You must provide your name, gender, and state!  Go <a href="groups2.php">back</a>.
    <?php else: ?>
      You are registered!  (Well, not really.)
    <?php endif ?>
  </body>
</html>
