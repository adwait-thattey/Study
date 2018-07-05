<!DOCTYPE html><!--register0.php-->
<html>
  <head>
    <title>Registered!</title>
  </head>
  <body>
    <h1>Hello, <?= htmlspecialchars($_GET['name']) ?>!</h1>
    <h1>You are a <?= htmlspecialchars($_GET['gender']) ?></h1>
    <h1>You are from <?= htmlspecialchars($_GET['state']) ?></h1>
  </body>
</html>




