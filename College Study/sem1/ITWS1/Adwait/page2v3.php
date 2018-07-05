<?php


$servername = "localhost";
$username = "projectgrp";
$password = "abada";
$dbname = "PROJECTTEMP";

$conn = new mysqli($servername, $username, $password, $dbname);
$sql = "SELECT * FROM CARS WHERE CARID=0";


$result = $conn->query($sql);

$row = $result->fetch_assoc();
$conn->close();


$conn = new mysqli($servername,$username,$password,$dbname);
$sql2 = "SELECT * FROM MORECARDETAILS WHERE CARID=1"#.$_GET["carid"];
$result2 = $conn->query($sql2);
$row2 = $result2->fetch_assoc();

$conn->close();

?>


<!DOCTYPE html>
<html>
<head>
	<title><?php echo $row["CARNAME"]; ?></title>
	
	<link rel="stylesheet" type="text/css" href="bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="purr.css">
 	<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">	
	
	<script>
		function sleep(ms) {
 		 return new Promise(resolve => setTimeout(resolve, ms));
		}
		globflag=1;
	</script>
	<script>
		CAR = { 	CARID :<?php echo $row["CARID"]; ?>,
	   			CARNAME : <?php echo "\"".$row["CARNAME"]."\""; ?>,
	    			COMPANYID :<?php echo $row["COMPANYID"]; ?> ,
	    			PRICE :<?php echo $row["PRICE"]; ?>,
	    			PRICEUNIT : <?php echo "\"".$row["PRICEUNIT"]."\""; ?>,
	    			MILEAGE : <?php echo $row["MILEAGE"]; ?>,
	  			TOPSPEED : <?php echo $row["TOPSPEED"]; ?> 
	  		 };	

	  	MORECAR = { CARID :<?php echo $row2["CARID"]; ?>,
			    IMAGE1 :<?php echo "\"".$row2["IMAGE1"]."\""; ?>,
			    IMAGE2 :<?php echo "\"".$row2["IMAGE2"]."\""; ?>,
			    IMAGE3 :<?php echo "\"".$row2["IMAGE3"]."\""; ?>, 
			    IMAGE4 :<?php echo "\"".$row2["IMAGE4"]."\""; ?>,
			    IMAGE5 :<?php echo "\"".$row2["IMAGE5"]."\""; ?>,
			    IMAGE6 :<?php echo "\"".$row2["IMAGE6"]."\""; ?>,
			    WEBLINK :<?php echo "\"".$row2["WEBLINK"]."\""; ?>
			
			};


	 </script> 		

	<style type="text/css">
		
		body {background: url("") no-repeat center center fixed;background-size: cover;}

		.midbox {color:white;width:40%;height:300px;top:250px;left:420px;background-color:black;opacity:0.8;border:3px solid white;position:relative;}

		.slide-animate-go-out-up {animation:go-out-up 0.5s forwards;}

		.slide-animate-go-out-left {animation:go-out-left 0.5s forwards;}

		.slide-animate-go-in-left {animation:go-in-left 2.5s forwards;}

		.slide-animate-go-in-up {animation:go-in-up 2.5s forwards;}


		@keyframes go-out-up {

			from {top:250px;width:40%;height:300px;}
			to {top:-450px;width:10%;height:50px;}
		}

		@keyframes go-in-up {


			from {top:1000px;width:10%;height:50px;}
			to {top:250px;width:40%;height:300px;}

		}

		@keyframes go-in-left {

			from {left:1500px;width:10%;height:50px;}
			to {left:420px;width:40%;height:300px;}


		}

		@keyframes go-out-left {

			from {left:420px;width:40%;height:300px;}

			to {left:-700px;width:10%;height:50px;}

		}

		/*NavBar Styles Begin */

		#rcorners1 {
 		    border-radius: 25px;
    		background: rgba(154,154,192,0.8);
    		padding: 30px; 
    		width: 500px;
    		height: 200px;  
    		margin-top:-50px;
    		margin-left: -60px;
    		color: white; 
    		font-size: 25px;

		}
		

		
		.form-control {
			width: 50%;
			float: right;
			margin-right: 50px;
		}

		.searchIt {
			color: white;
			border: 1 px solid black;
		}

	/*Nav Bar Styles End*/
	</style>
	<script>
		lastScrollTop = 0;
		var bkimages = new Array;
		
		for(i in MORECAR) {
		 		if(i=="CARID") continue;
			if(MORECAR[i]==="") break;
			if(i=="WEBLINK") break;

			var temp = MORECAR[i];
			bkimages.push(temp);
			
			}
		
		globflag=1;
		currentBkIndex=0;

	</script>
</head>
<body>
	
	<nav class="navbar fixed-top navbar-expand-lg navbar-dark bg-primary">
		  	<a class="navbar-brand" href="#">APNA CAR CHUNO</a>
		  	<button class="navbar-toggler" type="button">
		    <span class="navbar-toggler-icon"></span>
		  	</button>
		  	  <div class="collapse navbar-collapse" id="navbarSupportedContent">
		    	<ul class="navbar-nav mr-auto">

				    <li class="nav-item dropdown peep">
				        <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown">
				          Company
				        </a>
				        <div class="dropdown-menu">
				          <a class="dropdown-item" href="#" >Skoda</a>
				          <a class="dropdown-item" href="#">Renault</a>
				          <a class="dropdown-item" href="#">Mercedes</a>
				        </div>
		      		</li>
		      		<li class="nav-item dropdown peep">
				        <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown">
				          Types
				        </a>
				        <div class="dropdown-menu">
				          <a class="dropdown-item" href="#">Sedan</a>
				          <a class="dropdown-item" href="#">Hatchback</a>
				          <a class="dropdown-item" href="#">SUV</a>
				        </div>
				      	<li class="nav-item active peep">
				        <a class="nav-link" href="#">  About Us <span class="sr-only">(current)</span></a>
				      	</li>
				      	<li class="nav-item active peep">
				        <a class="nav-link" href="#">  Compare <span class="sr-only">(current)</span></a>
				      	</li>
				      	<form class="form-inline my-2 my-lg-0">
      					<input class="form-control mr-sm-2" type="search" placeholder="Search">
      					<button class="btn btn-outline-success my-2 my-sm-0 searchIt" type="submit">Search</button>
    					</form>
				      	<li class="nav-item active peep">
				        <a class="nav-link" href="#"><i class="fa fa-sign-in"></i>    Login <span class="sr-only">(current)</span></a>
				      	</li>
				      	
					</li>
		   		</ul>
		 	 </div>
		</nav>			



<!--<br><br><br><br><br><br><br><br>
		-->
		<div id="info" class="midbox">
			Hello World
		</div>


	


</body>
<script>


window.addEventListener('wheel', function(e) {
  if (e.deltaY < 0) {
    console.log('scrolling up');
    dispBk(currentBkIndex - 1);
	donothing();
    globflag-=2;
    if(globflag<1) globflag=4;
    dropThisContent(globflag);
   sleep(500).then(() => {
   // Do something after the sleep!
    showNextContent(globflag);
	});

  }
  if (e.deltaY > 0) {
    console.log('scrolling down');
    //document.getElementById('status').innerHTML = 'scrolling down';
    dispBk(currentBkIndex + 1);
	
	donothing();

    if(globflag>4) globflag=1;
   
    dropThisContent(globflag);
   sleep(500).then(() => {
  
    showNextContent(globflag);
	});
    
  }
});

function dispBk(n) {
	if(n>=bkimages.length) n = 0;
	if(n<0) n = bkimages.length - 1;
	document.body.style.backgroundImage = "url('" + bkimages[n] + "')";
	currentBkIndex = n;
	document.body.style.backgroundImage.onload = donothing();
}

function dropThisContent(i) {
	
	var X = document.getElementById("info");
 X.classList.remove("slide-animate-go-out-up");
 X.classList.remove("slide-animate-go-out-left");
 X.classList.remove("slide-animate-go-in-left");
 X.classList.remove("slide-animate-go-in-up");

  // without this it wouldn't work. Try uncommenting the line and the transition won't be retriggered.
  // Oops! This won't work in strict mode. Thanks Felis Phasma!
	void X.offsetWidth;

	if(!(globflag%2)) {
 		X.classList.add("slide-animate-go-out-up");
	}

	else {
		X.classList.add("slide-animate-go-out-left");
	}

}

function showNextContent(i) {
	
	var X = document.getElementById("info");
 X.classList.remove("slide-animate-go-out-up");
 X.classList.remove("slide-animate-go-out-left");
 X.classList.remove("slide-animate-go-in-left");
 X.classList.remove("slide-animate-go-in-up");

  // without this it wouldn't work. Try uncommenting the line and the transition won't be retriggered.
  // Oops! This won't work in strict mode. Thanks Felis Phasma!
	void X.offsetWidth;

	if(i==1) {

		X.innerHTML = "CAR NAME AND COMPANY NAME"

		X.classList.add("slide-animate-go-in-up");

	}

	if(i==2) {

		X.innerHTML = "FEW LINES ABOUT CAR"

		X.classList.add("slide-animate-go-in-left");

	}

	if(i==3) {

		X.innerHTML = "SPECIFICATIONS OF CAR"

		X.classList.add("slide-animate-go-in-up");

	}

	if(i==4) {

		X.innerHTML = "GALLERY AND OTHER OPTIONS"

		X.classList.add("slide-animate-go-in-left");

	}

	++globflag;
	


}

function donothing() {
console.log("I am doing nothing");

}
window.onload = function(){
	
	console.log("Window Loaded");	
	dispBk(0);
	showNextContent(globflag);

}






</script>

<script type="text/javascript" src="inline.js"></script>


<script
  src="https://code.jquery.com/jquery-3.2.1.min.js"
  integrity="sha256-hwg4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4="
  crossorigin="anonymous"></script>
  <script type="text/javascript" src="popper.min.js"></script>
  <script type="text/javascript" src="bootstrap.min.js"></script>
</html>
