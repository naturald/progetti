<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Shop</title>
    <link rel="icon" href="img/icon.png"/>
</head>

<body id="body">

    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">
    
    <header class="nav">
<?php 
    
    if(isset($_SESSION['acess']))
    {
        echo "<a href='carrello.php'> ";
        echo "<img src='img/carrello.png' id='carrello' class='carrello' style='display: block;'> "."</a> ";
        echo "<div style='position:absolute;top: 20px;right:30px;'> ";
        echo "<h2 id='hide' style='font-size: 15px; position: absolute; right: 150px;  width: 150px;'>".'benvenuto,'."<br>". $_SESSION['nome']."  ".$_SESSION['cognome']."</h2> ";
        echo "</div>";
        echo "<div style='display: block; width: fit-content;  margin-left: auto;  margin-right: auto;'> ";
        echo "<ul class='menu' style='display: table-cell;'> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>pag iniziale</h2></a></li> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>sconti</h2></a></li> ";
        echo "<li><a href='info.php' style='text-decoration:none;' ><h2 class='voci'>info</h2></a> </li> ";
        echo "<li><a href='session_destroy.php' style='text-decoration:none;'><h2 class='voci_hide' style='display: block;' id='hide2'>logout</h2></a></li>"."</ul> ";
                                
    }
    else
    {
        echo "<div style='position:absolute;top: 20px;right:30px;'>";
        echo "<button class='bottoni' id='btn' > ";
        echo "<h2 style='font-size: 18px;' >"."Login"."</h2>";            
        echo "</button> ";
        echo "</div> ";
        echo "<div style='display: block; width: fit-content;  margin-left: auto;  margin-right: auto;'> ";
        echo "<ul class='menu' style='display: table-cell;'> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>pag iniziale</h2></a></li> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>sconti</h2></a></li> ";
        echo "<li><a href='info.php' style='text-decoration:none;' ><h2 class='voci'>info</h2></a> </li> "."</ul>";
    }

    
  

?>
       
        </div>
        <a href="index.php">
            <img src="img/logo_sito.png" alt="" class="img_logo">
        </a>
        <center>
            <a href="" style="position: absolute;top:27px;" id="tre_menu">
                <span class="tre"></span>
                <span class="tre"></span>
                <span class="tre"></span>
            </a>
        </center>
    </header>

    
   <div class="cover">
        <div class="cover-opacita"></div>
        <div class="cover2">
            <div class="cover_text">
                <h1 class="titolo">
                    GUSCI
                </h1>
                <h2>
                    shop di abbigliamento online
                </h2>
            </div>
        </div>
    </div>

    <input type="text" class="lente" onkeyup="trova_art()" id="lente" placeholder="&#x1f50d;    cerca...">

    <div class="card">
        <ul class="cardList" id="lista">


<?php

    $conn=mysqli_connect("localhost"," gusci","","my_gusci");

    $articoli=mysqli_query($conn,"select * from articoli;");
    $articoli_A=mysqli_fetch_assoc($articoli);

    foreach($articoli as $articolo)
    {
        echo "<li id='banner'>";
            echo "<div class='banner'>";
                echo " <center>";
                    echo "  <a href='tameplate_banner.php?articolo=".$articolo['idart']."'>";
                        echo "<img class='img_banner' src='data:image;base64,".$articolo['img']."'  >";
                    echo "</a>";
                    echo " <div>";
                        echo " <h1 class='text_banner'>";
                            echo $articolo['titolo'];
                        echo "</h1><br>";
                        echo "<h3 class='text_banner'>";
                            echo $articolo['prezzo']." &#x20ac";
                        echo "</h3>";
                    echo " </div>";
                echo "</center>";
            echo "</div>";
        echo "</li>";

    
    }

    
    mysqli_close($conn);

   

?>            

        </ul>
    </div>

    <div id="login" class="modal" style="display: none;">
        <div id="con_login" class="con_modal"  > 
                <span class="close">&times;</span>
                <form name="sign_up" action="elogin.php?auten=1" method="POST">
                    <center>
                        <img src="img/logo_sito.png" style="height: 125px;width: 125px;">
                        <h1 style="padding-bottom: 40px;
                                font-size: 50px;
                                font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;">
                                GUSCI LOGIN </h1>
                        <input type="text" class="dati" style="margin-bottom: 20px;"  id="nome" name="nome" placeholder="Nome">
                    </center>
                    

                    <center>
                        <input type="password"  class="dati" style="margin-bottom: 20px;"  id="psw" name="psw"  placeholder="password">
                    </center>
                        
                    <center style="    margin-top: 50px;">
                        

                        <input type="submit" class="bottoni" name="login"  id="btn2" value="login"  style="padding: 13px 33px 13px 33px;
                                                                                            margin-top: 25px;
                                                                                            margin-bottom: 20px;
                                                                                            font-size: 15px;">
                    
                        <h5 id="sign_up">non ho un account</h5>
                        <h6  class="hide" style="color: red;position: relative; top: -130px;" id="allert3">nome o password sono sbagliati</h6>

                    </center>
                </form>
            </div>
            
            <div id="con_sign_up" class="con_modal_sign_in" style="position: relative;" > 
                <span class="close">&times;</span>
                <form name="sign_up" action="elogin.php?auten=2" method="POST">
                    <center>
                        <img src="img/logo_sito.png" style="height: 125px;width: 125px;">
                        <h1 style="padding-bottom: 40px;
                                font-size: 50px;
                                font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;">
                                GUSCI REGISTRAZIONE </h1>
                        <input type="text" class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung_sign()"  id="sign_nome" name="sign_nome" placeholder="Nome">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up">troppo lunga</h6><br>
                    <center>
                        <input type="text"  class="dati" style="margin-bottom: 20px;" id="sign_cognome" onkeyup="contr_lung_sign()"  name="sign_cognome"  placeholder="Cognome">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up2">troppo lunga</h6><br>
                    <center>
                        <input type="email"  class="dati" style="margin-bottom: 20px;"  id="mail" name="mail" placeholder="Mail">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up3">non e una mail</h6><br>
                    <center>
                        <input type="password"  class="dati" style="margin-bottom: 20px;" id="pass" name="pass" placeholder="Password">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up4">troppo corta</h6><br>
                    <center>
                        <h6 class="hide allert" id="err_gen_sign" style="position: absolute; top: 540px; margin-left: 15px;" >completa tutti i campi</h6>
                        <input type="submit" class="bottoni"  name="sign_up" value="registrati" id="btn2_sign"    style="padding: 13px 33px 13px 33px;                       
                                                                                                                        margin-top: 25px;
                                                                                                                        margin-bottom: 20px;
                                                                                                                        font-size: 15px;    
                                                                                                                        top: -25px;
                                                                                                                        position: relative;">
                                            
                        <h5 onclick="switch_modal()" style="position: relative;top:-15px;">ho gia un account</h5>

                    </center>
                </form>
            </div>
        </div> 
    </div> 
    
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    
    <script>
<?php
    
        if($_GET['err']==1)
        {
            echo 'document.getElementById("allert3").style.display="block";';
            echo 'document.getElementById("login").style.display="flex";';
        
        }
        else
        {
            if($_GET['err']==2)
            {
                echo <<<'EOT'
                document.getElementById("login").style.display="flex";
                document.getElementById("con_login").style.display="none";
                document.getElementById("con_sign_up").style.display="block";
                document.getElementById("sign_up").style.display="none";
                document.getElementById("allert3").style.display="none";
                document.getElementById("err_gen_sign").style.display="inline-block";
EOT;
            }
            else
            {
                if($_GET['err']==3)
                {
                    echo <<<'EOT'
                    document.getElementById("login").style.display="flex";
                    document.getElementById("con_login").style.display="none";
                    document.getElementById("con_sign_up").style.display="block";
                    document.getElementById("sign_up").style.display="none";
                    document.getElementById("allert3").style.display="none";
                    
EOT;
                    foreach($_SESSION['sub_err'] as $i)
                    {
                        if($i==1)
                        echo 'document.getElementById("allert_sign_up").style.display="block";';
                        
                        if($i==2)
                            echo 'document.getElementById("allert_sign_up2").style.display="block";';

                        if($i==3)
                            echo 'document.getElementById("allert_sign_up3").style.display="block";';

                        if($i==4)
                            echo 'document.getElementById("allert_sign_up4").style.display="block";';
                    }
                   
                }
            }
        }
    
?>
        document.getElementById("btn").onclick=function()
        {
            document.getElementById("login").style.display="flex";
        }
        
        var modal=document.getElementById("login");
        
        document.getElementById("sign_up").onclick=function()
        {
            document.getElementById("con_login").style.display="none";
            document.getElementById("con_sign_up").style.display="block";
            document.getElementById("sign_up").style.display="none";
            document.getElementById("allert3").style.display="none";
            spazzino();

        }
            
        window.onclick = function(event) 
        {
            if (event.target == modal)
            {
                document.getElementById("allert3").style.display="none";
                modal.style.display = "none";
                document.getElementById("nome").value="";
                document.getElementById("psw").value="";
                document.getElementById("sign_nome").value="";
                document.getElementById("sign_cognome").value="";
                document.getElementById("mail").value="";
                document.getElementById("pass").value="";
                document.getElementById("allert3").style.display="none";
                document.getElementById("allert_sign_up").style.display="none";
                document.getElementById("allert_sign_up2").style.display="none";
                document.getElementById("allert_sign_up3").style.display="none";
                document.getElementById("allert_sign_up4").style.display="none";
                document.getElementById("err_gen_sign").style.display="none";

            }
        }
  
<?php
    
            if($_GET['to_be_logged'])
            {
                echo 'modal.style.display = "flex";';
            }

?>  



    </script>
    
</body>
</html>

