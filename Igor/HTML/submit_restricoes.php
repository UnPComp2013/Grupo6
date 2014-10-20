<?php 
	for($i = 0; $i < 6; $i++) {
		for($j = 1; $j <= 5; $j++){		
			if(isset($_POST[$i+$j]))
			{
				echo " - ".$_POST[$i+$j];
			}
			else
			{
				echo " - 0";
			}
		}
		echo "<br>";
	}
?>
