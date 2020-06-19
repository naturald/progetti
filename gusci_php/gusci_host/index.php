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
<?php

    $conn=mysqli_connect("sql304.epizy.com","epiz_26047184","OoRpFIA6OPJp4CU","epiz_26047184_gusci");

    $articoli=mysqli_query($conn,"select * from articoli;");
    $articoli_A=mysqli_fetch_assoc($articoli);

    foreach($articoli as $articolo)
    {
        echo "<li>";
            echo "<div class='banner'>";
                echo " <center>";
                    echo "  <a href=''>";
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

    
    

?>            

        </ul>
    </div>

    <div id="login_regiser">

    </div>
        
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    
    
</body>
</html>

