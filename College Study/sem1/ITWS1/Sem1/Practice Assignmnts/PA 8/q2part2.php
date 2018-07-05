<!DOCTYPE html>
<html>
<body>

<?php
	
	
		//$str = "Hello Adwait. My Name is Adwait Thattey Adwait. Hello Everyone Once Again";
		function CountWords($str) {

		$arr = array();

		$arr = array_merge($arr,str_word_count($str,1));
		for($i = 0; $i < count($arr); $i++) {
		    $flag=0;
			
			for($j=0;$j<$i;++$j) {
				if(strcmp($arr[$j],$arr[$i])==0){$flag=1; break;}
			}

			if($flag==1) continue;

			$count=1;

			for($j=$i+1;$j<count($arr);++$j) {
				if(strcmp($arr[$j],$arr[$i])==0){++$count;}

			}
		    echo $arr[$i]."-->".$count;
		    echo "<br>";
		}
		
	}

	if(isset($_GET[str])){ CountWords($_GET[str]); exit;}
	
	
?>

<form action="<?php echo $_SERVER['PHP_SELF'] ?>">
	Enter Any String : <input type='text' length=20 name='str'><br>
	<input type='submit'>
</form>

</body>
</html>