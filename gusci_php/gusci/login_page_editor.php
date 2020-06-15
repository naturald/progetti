<?php
    session_start();
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<link rel="stylesheet" href="css/classi.css">
<link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">
<div id="login_cms" class="login_cms">
    <div id="login_cms_form" class="login_cms_form">
        <img src="img/logo_cms.png" alt=""  style="height: 75px;
                                                    width: 190px;
                                                    margin: auto;
                                                    margin-bottom: 30px;">                                                                  
            <h1 style="text-align:center;" class="space">LOGIN</h1>

            <form name="login_cms" style="display: flex; flex-direction: column; " action="login_page_editor.php?elab=true" method="POST">
                <input type="text" placeholder="Nome" id="nome_cms" name="nome_cms" class="dati_cms space">
                <input type="password" class="dati_cms space" id="pass_cms" name="pass_cms" placeholder="Password"><br>
                <input type="submit" class="bottoni space" id="btn_cms" value="Login" style="width: fit-content; 
                                                                                            margin: auto;
                                                                                            margin-bottom: 20px;">
                <h6 class="hide allert_cms" id="cms_alt">nome o password sbagliato</h6>
            </form>
    </div>
</div>
<?php 
    if(isset($_GET['elab']))
    {
        $conn=mysqli_connect("localhost","visitor","casa","gusci");

        //mysqli_escape_string();
        $login="select * from admin where nome='".$_POST['nome_cms']."' and psw='".$_POST['pass_cms']."';";
        $query=mysqli_query($conn,$login);
        $val=mysqli_fetch_assoc($query);
        if($val['idadmin'])
        {
            $_SESSION['idadmin']=$val['idadmin'];
            $_SESSION['nome']=$val['nome'];
            $_SESSION['cognome']=$val['cognome'];  
            $_SESSION['acess_cms']=true;
            header("location: page_editor.php");
            
        }
        else
            header("location: login_page_editor.php?err=true elab=true");        
                                   
    }
?>
</body>
</html>