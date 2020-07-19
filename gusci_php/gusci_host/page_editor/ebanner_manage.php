<?php
     session_start();
 
     if(isset($_SESSION['acess_cms']))
     {
        $conn=mysqli_connect("localhost"," gusci","","my_gusci");

        if($_GET['elimina'])
        {
            $articoli=mysqli_query($conn,"delete from articoli  where idart=".addslashes($_GET['elimina']).";");
            $reset_id=mysqli_query($conn,"select idart from articoli");
            $i=1;
            foreach($reset_id as $id)
            {
                mysqli_query($conn,"update articoli set idart = ".addslashes($i)."  where idart=".addslashes($id['idart'])." ;");
                
                $i++;
            }
            $set_AI=mysqli_query($conn,"alter table articoli AUTO_INCREMENT = ".addslashes($i)." ;");
            mysqli_close($conn);

            header("location: page_editor_manage.php"); 
        }

        if($_GET['modifica'])
        {
            $articoli=mysqli_query($conn,"select * from articoli where idart=".addslashes($_GET['modifica']).";");
            $articoli=mysqli_fetch_assoc($articoli);

            echo <<<'EOT'
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
                
                            <li><a href="page_editor.php" style="text-decoration:none;"><h2 class="voci">crea banner</h2></a></li>
                            <li><a href="page_editor_manage.php" style="text-decoration:none;" ><h2 class="voci">gestione banner</h2></a></li>
                            
                        </ul>

                    </div>

                    <img src="img/logo_cms.png" alt="" style="display:block;" class="img_logo_cms">

                    <a href='session_destroy.php'class='bottoni_hide' style='display: block; margin: 5px; text-decoration:none; position: absolute;right: 2%;top: 15px;' >
                        <h2  id='hide2' style="font-size: 19px;">logout</h2>
                    </a>

                    <center>
                        <a href="" style="position: absolute;top:27px;" id="tre_menu">
                            <span class="tre"></span>
                            <span class="tre"></span>
                            <span class="tre"></span>
                        </a>
                    </center>
            </div>
                <div style="display: flex;flex-direction: column;">
                    <h1 class="titolo_page_creator">MODIFICA BANNER</h1>
                    <div id="info_prodotto" class="info_prodotto">
                    
                        <button class="dati_file" id="fake_file">
                            <img id="pre_img" style="max-width: 290px;max-height: 290px;">
EOT;

                            echo '<img id="sele" src="data:image;base64,'.$articoli['img'].'">';

                        echo'</button>';

                        echo '<form action="banner_upload.php?modifica='.$articoli['idart'].'" style="display: flex;" method="POST" enctype="multipart/form-data">';

                        echo '<input type="file" style="display: none" name="img" value="" id="file">';
                        echo '<input type="hide" name="img_old" value="'.$articoli['img'].'" style="display: none;" >';
                        echo <<<'EOT'
                            <div style="display: flex;
                                        flex-direction: column;
                                        margin-left: 50px;">
EOT;

                                echo '<input type="text" class="dati_prodotto" id="titolo" placeholder="Titolo" name="titolo" value="'.$articoli['titolo'].'" style="font-size: 25px;">';
                                echo '<textarea class="dati_prodotto" id="descrizione" placeholder="Descrizione" name="descr"  style="height: 150px; resize: none;">'.$articoli['descrizione'].'</textarea>';

                                echo '<div style="display: flex;"> ';
                                    echo '<input type="number" class="dati_prodotto prezzo" id="Prezzo"  max=1000 min=1 value="'.$articoli['prezzo'].'" name="prezzo" placeholder="prezzo" style="margin-bottom: 0;
                                                                                                                                                                                            width: 80px;
                                                                                                                                                                                            font-size: 20px;"> ';
echo <<<'EOT'
                                    <h2 style="font-size: 27px;
                                                margin-top: 3px;
                                                margin-left: 10px;">
                                        &#x20ac
                                    </h2>                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                                </div>

                            </div>
                        </div> 
                        
                        <input type="submit" class="bottoni"  name="submit_2" value="Modifica" style="margin: auto;
                                                                                                margin-top: 6%;">
                        </form> 
                    
                    
                    <h6 class="hide" id="cms_alt_mod" style="position: relative;
                                                                bottom: -15px;
                                                                color: red;
                                                                margin: auto;">completa tutti i campi</h6>
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
EOT;
                    if($_GET['err']==1)
                    {
                        echo 'document.getElementById("cms_alt_mod").style.display="block";';
                    }
                    
echo <<<'EOT'
                </script>

            </body>
            </html>
EOT;
           
            

           
        }
     }
     else
        header("location: login_page_editor.php");     

    
 
?>

