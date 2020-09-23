<!DOCTYPE html>
<html lang="en" style="position: absolute; width: 100%; height: 100%;">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
</head>
<body style="background-color:black; margin:0;position: absolute; width: 100%; height: 100%;">
    <form action="usercheck.php" method="POST" style="display: flex; flex-direction:column; width: 430px; height: 200px; margin:auto; position: relative; top: 40%;">
        <h1 style="color: white;">Mettere password per accedere</h1>
        <input type="password" name="psw" style="border-radius: 8px; color:white; background-color:black; border: solid 1px white; padding:8px; width:max-content; margin:auto; outline:none;" >
        <input type="submit" name="sub" value="invia" style="border-radius: 8px; color:white; background-color:black; border: solid 1px white; padding:10px;width:max-content; margin:auto;">
    </form>
<?php
    session_start();
    if(isset($_POST['sub']))
    {

        $pas="jango";
        if($_POST['psw']===$pas)
        {
            echo "ciao";
            $_SESSION['access']="true";
            header("location: index.php");
        }
    }
?>
</body>
</html>
