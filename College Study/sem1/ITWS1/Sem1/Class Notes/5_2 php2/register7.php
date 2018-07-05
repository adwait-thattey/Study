<?php
    /***********************************************************************
     * register7.php
     * Implements a registration form for Groups.  Records registration 
     * in database.  Redirects user to groups7.php upon error.
     **********************************************************************/

    // validate submission
    $name=$_POST["name"];
    $leader=$_POST["leader"];
    $gender=$_POST["gender"];
    $state=$_POST["state"];
    if (empty($name) || empty($gender) || empty($state))
    {
        header("Location: http://localhost/groups/groups7.php");
        exit;
    }

    // connect to database
    $servername = "localhost";
    $username = "root";
    $password = "iiits@123";
    $dbname = "myDBPDO";

    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $sql = "INSERT INTO MyGroups (name, leader, gender, state)
    VALUES ('$name', '$leader', '$gender', '$state')";
    // use exec() because no results are returned
    $conn->exec($sql);
    echo "New record created successfully";
    $conn = null;
?>
