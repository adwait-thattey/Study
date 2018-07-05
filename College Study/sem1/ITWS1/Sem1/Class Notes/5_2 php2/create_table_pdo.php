<?php
$servername = "localhost";
$username = "adwaitthattey";
$password = "HailMikaelsons";
$dbname = "myDBPDO";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // sql to create table
    $sql = "CREATE TABLE MyGroups (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(30) NOT NULL,
    leader VARCHAR(30),
    gender VARCHAR(5) NOT NULL,
    state VARCHAR(50) Not Null
    )";

    // use exec() because no results are returned
    $conn->exec($sql);
    echo "Table MyGroups created successfully";
    }
catch(PDOException $e)
    {
    echo $sql . "<br>" . $e->getMessage();
    }

$conn = null;
?>

