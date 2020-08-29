<?php
    session_start();
    if(!($_SESSION['acess']==true))
        header("location: index.php?to_be_logged=true");

    $conn=mysqli_connect("localhost"," gusci","","my_gusci");
    $articolo=mysqli_query($conn,"select * from articoli where idart=".addslashes($_GET['articolo']).";");
    $articolo=mysqli_fetch_assoc($articolo);

    
    if(isset($_POST['submit_add_cart']))
    {
        
        $carrello_art=mysqli_query($conn,"select idart from carrello where idart=".addslashes($articolo['idart'])." and iduser=".addslashes($_SESSION['iduser']).";");
        $carrello_art=mysqli_fetch_assoc($carrello_art);
        if(strlen($carrello_art['idart'])<=0)
        {
            mysqli_query($conn,"insert into carrello values(".addslashes($articolo['idart']).",".addslashes($_SESSION['iduser']).",".addslashes($_POST['quantita']).");");
        }
        else
        {
            $quantita=mysqli_query($conn,"select quantita from carrello where idart=".addslashes($articolo['idart'])." and iduser=".addslashes($_SESSION['iduser']).";");
            $quantita=mysqli_fetch_array($quantita);
            $i=$quantita[0]+$_POST['quantita'];
            if($i>10)
                $i=10;

            mysqli_query($conn,"update carrello set quantita=$i;");


        }

       
    }
    
?>


<!DOCTYPE html>
<html>
<head>
    <title>Gusci - <?php echo $articolo['titolo'] ?></title>
    <link rel="icon" href="img/icon.png"/>
</head>
<body>
    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">

<header class="nav">
<?php 
    
    if(isset($_SESSION['acess']))
    {
        echo "<a id='hideCar' href='carrello.php'> ";
        echo "<img src='img/carrello.png' id='carrello' class='carrello' style='display: block;'> "."</a> ";
        echo "<div style='position:absolute;top: 20px;right:30px;'> ";
        echo "<h2 id='hide' style='font-size: 15px; position: relative; right: 40%;  width: 150px;'>".'Benvenuto,'."<br>". $_SESSION['nome']."  ".$_SESSION['cognome']."</h2> ";
        echo "</div>";
        echo "<div style='display: block; width: fit-content;  margin-left: auto;  margin-right: auto;'> ";
        echo "<ul class='menu' style='display: table-cell;'> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>pag iniziale</h2></a></li> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>sconti</h2></a></li> ";
        echo "<li><a href='info.php' style='text-decoration:none;' ><h2 class='voci'>info</h2></a> </li> ";
        echo "<li><a href='session_destroy.php' id='SesD' style='text-decoration:none;'><h2 class='voci_hide' style='display: block;' id='hide2'>logout</h2></a></li>"."</ul> ";
        echo <<<'EOT'
        </div>
        <h1 class="titNav" id="titNav" >
            GUSCI
        </h1>

        <button onclick="dropDownL()" class="DropL" id="DropL">  
            <span class="tre"></span>
            <span class="tre"></span>
            <span class="tre" style="margin-bottom: 0;"></span>
        </button>
        
        
        <div id="cont_dropL" class="cont_dropL" style="top:-15px;">
            <ul class="lista_cont_dropL">
EOT;
                echo '<li class="voci_cont_dropL" style="height: fit-content;">Benvevenuto<br>'. $_SESSION['nome'].'  '.$_SESSION['cognome'].'</li>';
echo <<<'EOT'
                <li class="voci_cont_dropL"><a href="index.php" class="text_voci_cont_dropL">Pag iniziale</a></li>
                <li class="voci_cont_dropL"><a href=""  class="text_voci_cont_dropL">Sconti</a></li>
                <li class="voci_cont_dropL"><a href="info.php"  class="text_voci_cont_dropL">Info</a></li>
                <li class="voci_cont_dropL"><a href="carrello.php"  class="text_voci_cont_dropL">Carrello</a></li>
                <li class="voci_cont_dropL" style="border: none;"><a href="session_destroy.php" class="text_voci_cont_dropL">Logout</a></li>
            </ul>
        </div>
       
EOT;
                                
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
        echo <<<'EOT'
        </div>
        <h1 class="titNav" id="titNav" >
            GUSCI
        </h1>
        <button onclick="dropDownL_Prelog()" class="DropL" id="DropL">  
            <span class="tre"></span>
            <span class="tre"></span>
            <span class="tre" style="margin-bottom: 0;"></span>
        </button>
            
        <div id="cont_dropL" class="cont_dropL" style="top:-15px;">
            <ul class="lista_cont_dropL">
                <li class="voci_cont_dropL"><a href="index.php" class="text_voci_cont_dropL">Pag iniziale</a></li>
                <li class="voci_cont_dropL"><a href=""  class="text_voci_cont_dropL">Sconti</a></li>
                <li class="voci_cont_dropL"><a href="info.php"  class="text_voci_cont_dropL">Info</a></li>
                <li class="voci_cont_dropL" style="border: none;"><h2 class="text_voci_cont_dropL" id="voce_login_drop" onclick="login()" >Login</h2></li>
            </ul>
        </div>
EOT;
    }

    
  

?>
       
        
        <a href="index.php">
            <img src="img/logo_sito.png" alt="" class="img_logo">
        </a>
        
      
        
        <button onclick="dropDownL_close()" class="DropL" style="display: none;" id="DropL_close">  
            <div style="width: 30px; height: 30px; position: relative; top: 10px;">
                <span style="transform: rotate(-45deg);height: 6px; width: 30px; background-color: white;display: block;"></span>
                <span style="transform: rotate(45deg);position: relative;height: 6px; width: 30px; background-color: white;display: block;top: -5px;"></span>
            </div>
        </button>

       
    </header>
    
        <div class="container_text_img">
            <?php
                echo '<img src="data:image;base64,'.$articolo['img'].'" alt="" 
                        class="img_tameplate">';
            ?>   
            
            <div class="testo_tameplate">
                <div>
                    <h1 style="margin-bottom: 15px;"><?php echo $articolo['titolo'] ?></h1>
                </div>
                <hr>
                <div>
                    <h4 style="margin-top: 15px;width: 600px;word-wrap: break-word;"><?php echo $articolo['descrizione'] ?></h4>
                </div>   
            </div>
            
        
        

            <div class="prezzo">
                <h1 style="position: relative;display: flex;margin-bottom: 30px;justify-content: center;">Prezzo: <?php echo $articolo['prezzo'] ?> &#x20ac</h1>
<?php 
    $quantita=mysqli_query($conn,"select quantita from carrello where idart=".addslashes($articolo['idart'])." and iduser=".addslashes($_SESSION['iduser']).";");
    $quantita=mysqli_fetch_array($quantita);
    if($quantita[0]<10)
    {
        echo '<form action="tameplate_banner.php?articolo='.$_GET['articolo'].'" method="POST">';
        echo '<div style="display: flex;justify-content: center;margin-bottom: 10px;">';
        echo '<h3 style="height: fit-content; top: 8px; margin-right: 10px; position: relative;">Quantità:</h3>';
        echo '<input type="number" class="dati_prodotto" name="quantita" style="font-size: 20px;width: 40px;margin-bottom: 15px;" value="1" min="1" max="10"> ';
        echo '</div>';
        if(strlen($quantita[0])<=0)
            $i=0;
        else
            $i=$quantita[0];
            
        echo '<h3 style="height: fit-content; top: 8px;margin-bottom: 20px; position: relative;">'.$i.' già nel tuo carrello </h3>';
        echo '<hr>';
        echo '<input type="submit" class="bottoni" name="submit_add_cart" style="margin-top: 15px;" value="aggiungi al carrelo">';
        echo '</form>';

    }
    else
    {
        echo '<h3 style="height: fit-content; top: 8px;margin-bottom: 20px; position: relative; width:300px; font-size: 17px;"> non puoi più aggiungere questo articolo hai raggiunto la quantita massima per singolo articolo di 10</h3>';
        echo '<hr>';
        echo '<button class="bottoni_fake">aggiungi al carrelo</button> ';

    }
    mysqli_close($conn);
                
?>
            </div>
        </div>
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>

</body>
</html>