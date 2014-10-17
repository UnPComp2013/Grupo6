<?php
	$DBHost = "localhost";  // localhost ou o IP do Banco
	$DBUser = "root";  // Usuário do Banco
	$DBPassword = "vertrigo";  // Senha do Banco
	$DBName = "gh";  // Nome do Banco de Dados
	
	$login = $_POST['usuario'];
	$senha = $_POST['senha'];
	$salt = $login.$senha; //Simular Codificação da senha
	
	//echo $login."\n".$senha;
	$Link = MySQL_Connect($DBHost, $DBUser, $DBPassword) or die ("Can't connect to MySQL");
	MySQL_Select_Db($DBName, $Link) or die ("Database ".$DBName." do not exists.");
	$Result = MySQL_Query("SELECT senha FROM professores WHERE senha='$salt'") or ("Can't execute query.");

	if (!MySQL_Num_Rows($Result))
	{
		echo "<p align=center class=infos>Conta não registrada, entre em contado com o administrador</p>";
	}else 
	{
		echo "<p style='background-color:black; color:white' align=center class=infos>Bem Vindo(a), <b>".$login."</b>!</p>";
	}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<style>
		table, td, th {
			border: 1px solid green;
		}

		th {
			background-color: green;
			color: white;
		}
		
		#title {
			background-color: black; 
			color:white;
		}
		
		#tableInput:hover {
			background-color: gray;
		}
		
		</style>
	</head>

<body>
<h1 align="center" id="title">Painel - Professor</h1>

<form name="input" action="submit_restricoes.php" method="post">
	<table align=center>
		<tr>
			<th></th>
			<th>Segunda</th>
			<th>Terça</th>
			<th>Quarta</th>
			<th>Quinta</th>
			<th>Sexta</th>
		</tr>
		<tr>
			<td>Primeiro Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="1"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="2"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="3"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="4"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="5"></p></td>
		</tr>
		<tr>
			<td>Segundo Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="6"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="7"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="8"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="9"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="10"></p></td>
		</tr>
		<tr>
			<td>Terceiro Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="11"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="12"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="13"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="14"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="15"></p></td>
		</tr>
		<tr>
			<td>Quarto Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="16"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="17"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="18"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="19"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="20"></p></td>
		</tr>
		<tr>
			<td>Quinto Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="21"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="22"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="23"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="24"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="25"></p></td>
		</tr>
		<tr>
			<td>Sexto Horário</td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="26"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="27"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="28"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="29"></p></td>
			<td id="tableInput"><p align="center"><input type="checkbox"  name="30"></p></td>
		</tr>
	</table>
<p align="center"><input type="submit"></p>
</form>

</body>
</html>
