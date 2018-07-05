<?php
    /***********************************************************************
     * groups6.php
     * Implements a registration form for Groups.  Submits to itself.
     * Generates list of states via an array.  Pre-populates name and 
     * state fields upon error.
     **********************************************************************/

    // array of states
    $STATES = array(
					"Andhra Pradesh",
					"Tamil Nadu",
					"Telangana",
					"Maharashtra",
					"Odisa",
					"Uttar Pradesh",
					"Madhya Pradesh",
					"Karnataka",
					"Delhi",
					"Goa",
					"Kerala",
					"Himachal Pradesh",
					"Gujrat",
					"Bengal",
					"Jharkhand",
					"Rajasthan"
				);

    // if form was actually submitted, check for error
    if (isset($_POST["action"]))
    {
        if (empty($_POST["name"]) || empty($_POST["gender"]) || empty($_POST["state"]))
            $error = true;
    }
?>

<!DOCTYPE html>

<html>
  <head>
    <title>Groups</title>
  </head>
  <body>
    <div style="text-align: center">
      <h1>Register for Groups</h1>
      <?php if (isset($error)): ?>
        <div style="color: red;">You must fill out the form!</div>
      <?php endif ?>
      <br><br>
      <form action="groups6.php" method="post">
        <table style="border: 0; margin-left: auto; margin-right: auto; text-align: left">
          <tr>
            <td>Name:</td>
            <td><input name="name" type="text" value="<?php if (isset($_POST["name"])) echo htmlspecialchars($_POST["name"]) ?>"></td>
          </tr>
          <tr>
            <td>Leader:</td>
            <td><input name="leader" type="checkbox"></td>
          </tr>
          <tr>
            <td>Gender:</td>
            <td>
              <input name="gender" type="radio" value="F" <?php if($_POST["gender"]=="F") echo checked ?>> F
              <input name="gender" type="radio" value="M" <?php if($_POST["gender"]=="M") echo checked ?>> M
            </td>
          </tr>
          <tr>
            <td>State:</td>
            <td>
              <select name="state">
                <option value=""></option>
                <?php 
                    foreach ($STATES as $state)
                    {
                        if (isset($_POST["state"]) && $_POST["state"] == $state)
                            echo "<option selected='selected' value='$state'>$state</option>";
                        else
                            echo "<option value='$state'>$state</option>";
                    }
                ?>
              </select>
            </td>
          </tr>
        </table>
        <br><br>
        <input name="action" type="submit" value="Register!">
      </form>
    </div>
  </body>
</html>
