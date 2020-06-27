<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Carrello</title>
    <link rel="icon" href="img/icon.png"/>
</head>
<body>
    
    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">
    <style>
        .banner_carrello
        {
            border: solid 1px;
            display:flex;
            margin-top:10px;
            border-radius: 15px;
            padding: 10px;
            position: relative;
        }
    

    </style>
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

    <div style="position: absolute;
                top: 120px;
                width: 100%;">

        <h1 style="text-align: center;
                   margin-bottom: 18px;">CARRELLO</h1>
                   
        <div style="width: 80%;
                    height: 650px;
                    border-top: solid 2px black;
                    border-bottom: solid 2px black;
                    position:relative;
                    overflow: auto;
                    margin:auto;">
<?php
           $conn=mysqli_connect("localhost"," gusci","","my_gusci");

           $articoli=mysqli_query($conn,"select * from articoli;");
       
           foreach($articoli as $articolo)
           {   
                echo '<div class="banner_carrello">';
                echo '<img src="data:image;base64,'.$articolo['img'].'"  style="height: 130px;">';
                echo '<h1 style=" height: fit-content;
                                position: relative;
                                top: 40px;
                                left: 10%;">';
                echo $articolo['titolo'].'</h1>';
                echo '<h2 style=" height: fit-content;
                                position: absolute ;
                                top: 56px;
                                left: 60%;">
                      Prezo: '.$articolo['prezzo'].' &#x20ac </h2>';
                echo '<img src="img/cancella.png" alt="" style="position: absolute;
                                                                right: 10px;
                                                                height:40px;
                                                                border-radius: 10px;">';
                echo '<h3 style="position: absolute; width: fit-content;  right: 60px; top: 120px;">Quantità</h3>';
                echo ' <input type="number" value="1" style="position: absolute; width: 30px; height: 30px;  right: 10px; padding-left: 10px; top: 110px; border-radius: 10px;" >';
                echo '</div>';
                $prezzo_tot+=$articolo['prezzo'];
           }
?> 

        </div>
        <h1 style="position:relative;top:20px;left:10%">Prezzo totale: <?php echo $prezzo_tot ?> &#x20ac</h1>
        <button class="bottoni" style="position: absolute;
                                       right: 17%;
                                       top: 730px;">
            <h2>
                Paga
            </h2>
        </button>
    </div>

  

    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>

</body>
</html>