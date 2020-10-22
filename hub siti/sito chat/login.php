<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/class.css">
    <title>login</title>
</head>
<body>
    <div style="height: 100%;width:100%;display:flex;flex-direction:column;justify-content:center">
        <div style="width: 300px;height:350px;box-shadow: 0px 0px 20px -5px; border-radius: 50px;margin:auto;position:relative">
            <h1 class="tit_log">Identificati</h1>
            <form action="login.php?log=true" style="margin: auto;width:max-content;margin-top:100px;display:flex;flex-direction:column;height:200px" method="POST">
                <input type="text" class="input_log" name="name" id="name" required autocomplete="off">
                <label for="name" >Nome</label>
                <input type="submit" value="Entra" name="sub" class="sub_log" style="margin:auto;width:100px;"></input>
            </form> 

        </div>
    </div>
</body>
</html>
<?php
    if(isset($_POST['sub']))
    {
        $_SESSION['log']=true;
        $_SESSION['name']=$_POST['name'];
        header("location: index.php");
    }
?>