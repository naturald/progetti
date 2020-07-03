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

//(isset($_POST['sign_nome']) && isset($_POST['sign_cognome']) && isset($_POST['pass']) && isset($_POST['mail'])) || (isset($_POST['psw']) && isset($_POST['nome']))
  
    $conn=mysqli_connect("localhost"," gusci","","my_gusci");

    if($_GET['auten']==1)
    {
        if(strlen($_POST['psw'])>0 && strlen($_POST['nome'])>0)
        {
            $pass=hash("sha512", $_POST['psw']);
            $login="select * from users where name='".addslashes($_POST['nome'])."' and psw='".addslashes($pass)."';";
            $query=mysqli_query($conn,$login);
            $val=mysqli_fetch_assoc($query);
            if(strlen($val['iduser'])>0)
            {
                $_SESSION['iduser']=$val['iduser'];
                $_SESSION['nome']=$val['name'];
                $_SESSION['cognome']=$val['surname'];  
                $_SESSION['acess']=true;
                mysqli_close($conn);
                header("location: index.php");
                
            }
            else
            {
                mysqli_close($conn);
                header("location: index.php?err=1");  
            }
            
        } 
        else
        {
            mysqli_close($conn);
            header("location: index.php?err=1"); 
        }
    }
    else
    {
        if($_GET['auten']==2)
        {
            
            if(strlen($_POST['sign_nome'])>0 && strlen($_POST['sign_cognome'])>0 && strlen($_POST['mail'])>0 && strlen($_POST['pass'])>0)
            {
                if(strlen($_POST['pass'])>=5 && strpos($_POST['mail'], '@') !== false && strlen($_POST['sign_nome'])<41 && strlen($_POST['sign_cognome'])<41 )
                {
                    $pass=hash("sha512", $_POST['pass']);
                    $sign_in="insert users values(null,'".addslashes($_POST['sign_nome'])."','".addslashes($_POST['sign_cognome'])."','".addslashes($pass)."','".addslashes($_POST['mail'])."');";
                    mysqli_query($conn,$sign_in);
                    $text_get_idUser="select iduser from users where email ='".addslashes($_POST['mail'])."';";
                    $get_idUser=mysqli_query($conn,$text_get_idUser);
                    $iduser=mysqli_fetch_array($get_idUser);
                    $_SESSION['iduser']=$iduser[0];
                    $_SESSION['nome']=$_POST['sign_nome'];
                    $_SESSION['cognome']=$_POST['sign_cognome'];
                    $_SESSION['acess']=true;
                    mysqli_close($conn);
                    header("location: index.php");
                }
                else
                {
                    mysqli_close($conn);
                    $sub_err=array();
                    if(strlen($_POST['sign_nome'])>40)
                        array_push($sub_err,1);

                    if(strlen($_POST['sign_cognome'])>40)
                        array_push($sub_err,2);

                    if(strpos($_POST['mail'], '@') === false)
                        array_push($sub_err,3); 
                        
                    if(strlen($_POST['pass'])<5)
                        array_push($sub_err,4);

                    $_SESSION['sub_err']=$sub_err;
                    header("location: index.php?err=3"); 
                }

            }
            else
            {
                mysqli_close($conn);
                header("location: index.php?err=2"); 
            }
        }
        else
        {
            mysqli_close($conn);
            header("location: index.php");       
        }

    }
  
?>
</body>
</html>