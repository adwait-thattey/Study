<?php
$servername = "localhost";
$username = "root";
$password = "iiits@123";
$dbname = "myDBPDO";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
$sql = "SELECT * FROM MyGroups";
//$sql = "SELECT * FROM MyGroups WHERE state='Tamil Nadu'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<center><table style=\"width:100%;text-align:left;\"><tr><th>ID</th><th>Name</th><th>Leader</th><th>Gender</th><th>State</th></tr>";
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>".$row["id"]."</td><td>".$row["name"]."</td><td>".$row["leader"]."</td><td>".$row["gender"]."</td><td>".$row["state"]."</td></tr>"."<br>";
    }
    echo "</table></center>";
} else {
    echo "0 results";
}
$conn->close();
?>

