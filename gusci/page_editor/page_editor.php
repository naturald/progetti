<?php
    session_start();
 
    if(isset($_SESSION['acess_cms']))
    {
        echo "<div style='position:absolute;top: 20px;right:30px;'> ";
        echo "<h2 id='hide_' style='font-size: 15px; position: absolute; right: 150px;  width: 150px;'>".'benvenuto,'."<br>". $_SESSION['nomeAdmin']."  ".$_SESSION['cognomeAdmin']."</h2> ";
        echo "</div>";
    }
    else
        header("location: login_page_editor.php");     


    
?>
<!DOCTYPE html>
<html>
<head>
    <title>Gusci Page editor</title>
    <link rel="icon" href="../img/icon.png"/>
</head>
<body>
    
    <link rel="stylesheet" href="../css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">
    

    <div class="nav_page_editor">
    
        <div style="display: block;
                    width: fit-content;
                    margin-left: auto; 
                    margin-right: auto;">

            <ul class="menu" style="display: table-cell;">
    
                <li><a href="page_editor.php" style="text-decoration:none;"><h2 class="voci2">crea banner</h2></a></li>
                <li><a href="page_editor_manage.php" style="text-decoration:none;" ><h2 class="voci2">gestione banner</h2></a></li>
                
            </ul>

        </div>

        <img src="../img/logo_cms.png" alt="" style="display:block;" class="img_logo_cms">

        <a href='../session_destroy.php'class='bottoni_hide' style='display: block; margin: 5px; text-decoration:none; position: absolute;right: 2%;top: 15px;' >
            <h2  id='hide2' style="font-size: 19px;">logout</h2>
        </a>

       
</div>
    <div style="display: flex;flex-direction: column;">
        <h1 class="titolo_page_creator">CREAZIONE BANNER</h1>
        <div id="info_prodotto" class="info_prodotto">
        
            <button class="dati_file" id="fake_file">
                <img id="pre_img" style="max-width: 290px;max-height: 290px;">
                <p id="sele" style="display: block;">scegli immagine prodotto</p>
            </button>

            <form action="banner_upload.php" style="display: flex;" method="POST" enctype="multipart/form-data">

                <input type="file" style="display: none" name="img" value="" id="file">
                

                <div style="display: flex;
                            flex-direction: column;
                            margin-left: 50px;">

                    <input type="text" class="dati_prodotto" id="titolo" placeholder="Titolo" name="titolo" style="font-size: 25px;">
                    <textarea class="dati_prodotto" id="descrizione" placeholder="Descrizione" name="descr"  style="height: 150px; resize: none;"></textarea>

                    <div style="display: flex;"> 
                        <input type="number" class="dati_prodotto prezzo" max=1000 min=1 id="Prezzo" name="prezzo" placeholder="prezzo" style="margin-bottom: 0;
                                                                                                                                                width: 80px;
                                                                                                                                                font-size: 20px;margin: 0;"> 
                        <h2 style="font-size: 27px;
                                    margin-top: 3px;
                                    margin-left: 10px;">
                            &#x20ac
                        </h2>                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                    </div>

                </div>
            </div> 
            
            <input type="submit" class="bottoni"  name="submit" value="Crea" style="margin: auto;
                                                                                    margin-top: 6%;">
            </form> 
        
        
        <h6 class="hide" id="cms_alt_con" style="position: relative;
                                                    bottom: -15px;
                                                    color: red;
                                                    margin: auto;">completa tutti i campi</h6>

        <h6 class="hide" id="cms_succ" style="position: relative;
                                                    bottom: -15px;
                                                    color: green;
                                                    margin: auto;">operazione completata con successo</h6>
    </div>

    
    <script type="text/javascript" src="../js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="../js/libreria.js"></script>
    <script type="text/javascript" src="../js/codice.js"></script>
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
        
<?php
        if($_GET['err']==1)
        {
            echo 'document.getElementById("cms_alt_con").style.display="block";';
        }
        if($_GET['err']==2)
        {
            echo 'document.getElementById("cms_alt_con").innerHTML="titolo troppo lungho massimo 17 caratteri ";';
            echo 'document.getElementById("cms_alt_con").style.display="block";';
        }
        if($_GET['err']==3)
        {
            echo 'document.getElementById("cms_alt_con").innerHTML=" massimo immagini da 300x300 px png,jpeg,jpg,pdf";';
            echo 'document.getElementById("cms_alt_con").style.display="block";';
        }
        if($_GET['done']==1)
        {
            echo 'document.getElementById("cms_succ").style.display="block";';
        }
?>
    </script>

</body>
</html>