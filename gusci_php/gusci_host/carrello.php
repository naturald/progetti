<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Carrello</title>
    <link rel="icon" href="img/logo_sito.png"/>
</head>
<body>
    
    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">

    <header class="nav">
         
    <div style="display: block;
                width: fit-content;
                margin-left: auto; 
                margin-right: auto;">

        <ul class="menu" style="display: table-cell;">

            <li><a href="index.html" style="text-decoration:none;"><h2 class="voci">pag iniziale</h2></a></li>
            <li><a href="index.html" style="text-decoration:none;"><h2 class="voci">sconti</h2></a></li>
            <li><a href="info.html" style="text-decoration:none;" ><h2 class="voci">info</h2></a> </li>
            <li><a href="index.html" style="text-decoration:none;"><h2 class="voci_hide" id="hide2">logout</h2></a></li>

        </ul>
    
    </div>
    <a href="index.html">
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
                    margin-left: 125.7px;
                    border-top:solid 2px black;
                    border-bottom:solid 2px black;
                    position: fixed;">

        </div>
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