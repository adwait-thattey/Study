<?php 
$current = $_GET[cr1];
$value = $_GET[cr1];

if($_GET[country]=="KR") $value = 1.59*$current;
else if($_GET[country]=="USD") $value = 0.015*$current;
else if($_GET[country]=="AUD") $value = 0.020*$current;
else if($_GET[country]=="EURO") $value = 0.013*$current;
else if($_GET[country]=="YEN") $value = 1.74*$current;


	echo $_GET[cr1]." Rupees is equal to ".$value." ".$_GET[country]; 


?>