<?php
    session_start();
    if(!($_SESSION['acess']==true))
        header("location: index.php");

    $conn=mysqli_connect("localhost"," gusci","","my_gusci");
    $articolo=mysqli_query($conn,"select * from articoli where idart=".addslashes($_GET['articolo']).";");
    $articolo=mysqli_fetch_assoc($articolo);

    
    
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
                echo '<img src="data:image;base64,'.$articolo['img'].'" alt="" style="position: relative;height: inherit;display: flex;margin-left: 0;margin-right: 0;flex-direction: column;justify-content: center;">';
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

            <div style="height: fit-content;position: absolute;top: 40%;right: 7%;">
                <h1 style="position: relative;display: flex;margin-bottom: 10px;justify-content: center;">Prezzo: <?php echo $articolo['prezzo'] ?>$</h1>
                <hr>
                <button class="bottoni" style="margin-top: 15px;"> aggiungi al carrelo</button>
            </div>
        </div>
</body>
</html>