<?php
    session_start();
    if(!($_SESSION['acess']==true))
        header("location: index.php");

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
    
        <div style="height: 60%;display: flex;position: absolute;top: 25%;width: 100%;">
            <?php
                echo '<img src="data:image;base64,'.$articolo['img'].'" alt="" 
                        style="position: relative;height: inherit;display: flex;margin-left: 20px;margin-right: 0;flex-direction: column;justify-content: center;">';
            ?>   
            
            <div style="position: relative;width: 600px;height: 100%;left: 11%;justify-content: center;overflow: hidden;">
                <div>
                    <h1 style="margin-bottom: 15px;"><?php echo $articolo['titolo'] ?></h1>
                </div>
                <hr>
                <div>
                    <h4 style="margin-top: 15px;width: 600px;word-wrap: break-word;"><?php echo $articolo['descrizione'] ?></h4>
                </div>   
            </div>

            <div style="height: fit-content;position: absolute;top: 30%;right: 7%;">
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

</body>
</html>