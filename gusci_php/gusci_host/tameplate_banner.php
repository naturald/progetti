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
    <link rel="stylesheet" href="./Document_files/classi.css">
    <link href="./Document_files/css" rel="stylesheet">
    <header class="nav">
         
        <div style="display: block;
                    width: fit-content;
                    margin-left: auto; 
                    margin-right: auto;">
    
            <ul class="menu" style="display: table-cell;">
    
                <li><a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/index.html" style="text-decoration:none;"><h2 class="voci">pag iniziale</h2></a></li>
                <li><a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/index.html" style="text-decoration:none;"><h2 class="voci">sconti</h2></a></li>
                <li><a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/info.html" style="text-decoration:none;"><h2 class="voci">info</h2></a> </li>
                <li><a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/index.html" style="text-decoration:none;"><h2 class="voci_hide" id="hide2">logout</h2></a></li>
    
            </ul>
        
        </div>
        <a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/index.html">
            <img src="./Document_files/logo_sito.png" alt="" class="img_logo">
        </a>
        <center>
            <a href="file:///C:/Users/marco/Desktop/progetti/gusci%20site/porva.html" style="position: absolute;top:27px;" id="tre_menu">
                <span class="tre"></span>
                <span class="tre"></span>
                <span class="tre"></span>
            </a>
        </center>
    </header>
    
        <div style="height: 60%;display: flex;position: absolute;top: 50%;width: 100%;">
            <?php
                echo '<img src="data:image;base64,'.$articolo['img'].'" alt="" style="position: relative;height: inherit;display: flex;margin: auto;margin-left: 0;margin-right: 0;flex-direction: column;justify-content: center;">';
            ?>   
            
            <div style="position: relative;top: 20%;width: 600px;height: 100%;left: 11%;justify-content: center;">
                <div>
                    <h1 style="margin-bottom: 15px;"><?php echo $articolo['titolo'] ?></h1>
                </div>
                <hr>
                <div>
                    <h4 style="margin-top: 15px;"><?php echo $articolo['descrizione'] ?></h4>
                </div>   
            </div>

            <div style="height: fit-content;position: absolute;top: 45%;right: 7%;">
                <h1 style="position: relative;display: flex;margin-bottom: 10px;justify-content: center;">Prezzo: <?php echo $articolo['prezzo'] ?>$</h1>
                <hr>
                <button class="bottoni" style="margin-top: 15px;"> aggiungi al carrelo</button>
            </div>
        </div>
</body>
</html>