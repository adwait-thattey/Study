<?php 
    /***********************************************************************
     * groups7.php
     * Implements a registration form for Groups.  Submits to register7.php.
     **********************************************************************/
?>

<!DOCTYPE html>

<html>
  <head>
    <title>Groups</title>
  </head>
  <body>
    <div style="text-align: center">
      <h1>Register for Groups</h1>
      <br><br>
      <form action="register7.php" method="post">
        <table style="border: 0; margin-left: auto; margin-right: auto; text-align: left">
          <tr>
            <td>Name:</td>
            <td><input name="name" type="text"></td>
          </tr>
          <tr>
            <td>Leader:</td>
            <td><input name="leader" type="checkbox"></td>
          </tr>
          <tr>
            <td>Gender:</td>
            <td>
              <input name="gender" type="radio" value="F"> F
              <input name="gender" type="radio" value="M"> M
            </td>
          </tr>
          <tr>
				<td>State:</td>
            <td>
              <select name="state">
                <option value=""></option>
                <option value="Andhra Pradesh">Andhra Pradesh</option>
                <option value="Tamil Nadu">Tamil Nadu</option>
                <option value="Telangana">Telangana</option>
                <option value="Maharashtra">Maharashtra</option>
                <option value="Odisa">Odisa</option>
                <option value="Uttar Pradesh">Uttar Pradesh</option>
                <option value="Madhya Pradesh">Madhya Pradesh</option>
                <option value="Karnataka">Karnataka</option>
                <option value="Delhi">Delhi</option>
                <option value="Goa">Goa</option>
                <option value="Kerala">Kerala</option>
                <option value="Himachal Pradesh">Himachal Pradesh</option>
                <option value="Gujrat">Gujrat</option>
                <option value="Bengal">Bengal</option>
                <option value="Jharkhand">Jharkhand</option>
                <option value="Rajasthan">Rajasthan</option>
              </select>
            </td>
          </tr>
        </table>
        <br><br>
        <input type="submit" value="Register!">
      </form>
    </div>
  </body>
</html>
