<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Shop</title>
    <link rel="icon" href="img/logo_sito.png"/>
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
    echo "<button class='bottoni' id='btn'onclick='login()' > ";
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

            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/maglia.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Maglia 
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/scarpa.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Scarpa
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/tazza.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Tazza 
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/cappello.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Cappello 
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
                
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/berretto.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Berretto
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/cintura.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Cintura
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/san_pei.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                San Pei 
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
            <li>
                <div class="banner">
                    <center>
                        <a href="">
                            <img src="img/felpa.png" class="img_banner">
                        </a>
                        <div>
                            <h1 class="text_banner">
                                Felpa 
                            </h1><br>
                            <h3 class="text_banner">
                                200 &#x20ac
                            </h3>
                        </div>
                    </center>
                </div>
            </li>
        </ul>
    </div>

    <div id="login_regiser">

    </div>
        
        
  
    
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    
    
</body>
</html>

