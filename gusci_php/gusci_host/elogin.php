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
   

   
   if((isset($_POST['sign_nome']) && isset($_POST['sign_cognome']) && isset($_POST['pass']) && isset($_POST['mail'])) || (isset($_POST['psw']) && isset($_POST['nome'])))
   {
       if((strlen($_POST['sign_nome'])>0 && strlen($_POST['sign_cognome'])>0 && strlen($_POST['pass'])>0 && strlen($_POST['mail'])>0) || (strlen($_POST['psw'])>0 && strlen($_POST['nome'])>0))
       {
            $conn=mysqli_connect("sql304.epizy.com","epiz_26047184","OoRpFIA6OPJp4CU","epiz_26047184_gusci");

            if($_GET['auten']==1)
            {
                //mysqli_escape_string();
                $login="select * from users where name='".addslashes($_POST['nome'])."' and psw='".addslashes($_POST['psw'])."';";
                $query=mysqli_query($conn,$login);
                $val=mysqli_fetch_assoc($query);
                if($val['iduser'])
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

            if($_GET['auten']==2)
            {
                $sign_in="insert users values(null,'".addslashes($_POST['sign_nome'])."','".addslashes($_POST['sign_cognome'])."','".addslashes($_POST['pass'])."','".addslashes($_POST['mail'])."');";
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
                header("location: index.php");     
            }
                
            
            mysqli_close($conn);
       } 
       else
         header("location: index.php");       
   }
   else
    header("location: index.php"); 
?>
</body>
</html>