<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Page editor</title>
    <link rel="icon" href="img/logo_sito.png"/>
</head>
<body>
    
    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">

    <div id="login_cms" class="login_cms">
        <div id="login_cms_form" class="login_cms_form">
            <img src="img/logo_cms.png" alt=""  style="height: 75px;
                                                        width: 190px;
                                                        margin: auto;
                                                        margin-bottom: 30px;">                                                                  
            <h1 style="text-align:center;" class="space">LOGIN</h1>
            <input type="text" placeholder="Nome" id="nome_cms" class="dati_cms space">
            <input type="password" class="dati_cms space" id="pass_cms" placeholder="Password">
            <button class="bottoni space" id="btn_cms" onclick="contr_cms()" style="width: fit-content; 
                                                                                    margin: auto;
                                                                                    margin-bottom: 20px;">
                Login
            </button>
            <h6 class="hide allert_cms" id="cms_alt">nome o password sbagliato</h6>
        </div>
    </div>

    <header class="nav_page_editor">
    
        <div style="display: block;
                    width: fit-content;
                    margin-left: auto; 
                    margin-right: auto;">

            <ul class="menu" style="display: table-cell;">
    
                <li><a href="index.php" style="text-decoration:none;"><h2 class="voci">pag iniziale</h2></a></li>
                <li><a href="page_editor.php" style="text-decoration:none;"><h2 class="voci">crea banner</h2></a></li>
                <li><a href="page_editor.php" style="text-decoration:none;" ><h2 class="voci">modifica banner</h2></a> </li>
                <li><a href="page_editor.php" style="text-decoration:none;" ><h2 class="voci">elimina banner</h2></a> </li>
    
            </ul>
        
        </div>

            <img src="img/logo_cms.png" alt="" class="img_logo_cms">

        <center>
            <a href="" style="position: absolute;top:27px;" id="tre_menu">
                <span class="tre"></span>
                <span class="tre"></span>
                <span class="tre"></span>
            </a>
        </center>
    </header>
    <div style="display: flex;flex-direction: column;">
        <h1 class="titolo_page_creator">CREAZIONE BANNER</h1>
        <div id="info_prodotto" class="info_prodotto">
            <input type="file" style="display: none" id="file">
            <button class="dati_file" id="fake_file">
                <img id="pre_img" style="max-width: 290px;max-height: 290px;">
                <p id="sele" style="display: block;">scegli immagine prodotto</p>
            </button>
            <div style="display: flex;
                        flex-direction: column;
                        margin-left: 50px;">
                <input type="text" class="dati_prodotto" id="titolo" placeholder="Titolo" style="font-size: 25px;">
                <textarea class="dati_prodotto" id="descrizione" placeholder="Descrizione" style="height: 150px; resize: none;"></textarea>
                <div style="display: flex;"> 
                    <input type="number" class="dati_prodotto prezzo" id="Prezzo" placeholder="prezzo" style="margin-bottom: 0;
                                                                                                                width: 60px;
                                                                                                                font-size: 20px;"> <h2 style="font-size: 27px;
                                                                                                                                            margin-top: 3px;
                                                                                                                                            margin-left: 10px;">
                                                                                                                                        &#x20ac
                                                                                                                                    </h2>
                                </div>
            </div>
        </div>
        <button class="bottoni" onclick="crea_contr()" style="margin: auto;
                                                            margin-top: 6%;">
            <h2>
                Crea
            </h2>
        </button>
        <h6 class="hide" id="cms_alt_con" style="position: relative;
                                                bottom: -15px;
                                                color: red;
                                                margin: auto;">completa tutti i campi</h6>
    </div>
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    <script>
       
        document.getElementById("fake_file").onclick=function()
        {
            document.getElementById("file").click();
        }
        $("#file").change(function() 
        {
            document.getElementById("sele").style.display="none";
            pre_img(this); 
        });


    </script>
 
</body>
</html>