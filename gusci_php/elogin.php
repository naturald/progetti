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
<?php
   
   $conn=mysqli_connect("localhost","visitor","casa","gusci");
       if(isset($_POST['sign_nome']) && isset($_POST['sign_cognome']) && isset($_POST['pass']) && isset($_POST['mail']))
       {
           $sign_in="insert users values(null,'".$_POST['sign_nome']."','".$_POST['sign_cognome']."','".$_POST['pass']."','".$_POST['mail']."');";
           mysqli_query($conn,$sign_in);
           $_SESSION['acess']=true;
           $text_get_idUser="select iduser from users where email ='".$_POST['mail']."';";
           $get_idUser=mysqli_query($conn,$text_get_idUser);
           $iduser=mysqli_fetch_array($get_idUser);
           $_SESSION['iduser']=$iduser[0];
           $_SESSION['nome']=$_POST['sign_nome'];
           $_SESSION['cognome']=$_POST['sign_cognome'];
           echo $_SESSION['iduser'] ;
           header("location: index.php");
       }
       else
       {
           header("location: index.php");
       }
?>
</body>
</html>