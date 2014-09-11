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
		echo "<p align=center class=infos>Bem Vindo(a), <b>".$login."</b>!</p>";
	}
?>
