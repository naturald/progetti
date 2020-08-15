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

    <h1 class="titolo_page_creator">GESTIONE BANNER</h1>
    
    <div class="card" style="top: 0;">
        <ul class="cardList" id="lista">
<?php

    $conn=mysqli_connect("localhost"," gusci","","my_gusci");

    $articoli=mysqli_query($conn,"select * from articoli;");
    $articoli_A=mysqli_fetch_assoc($articoli);

    foreach($articoli as $articolo)
    {
        echo "<li>";
            echo "<div class='banner_manage'>";
                echo"<a href='ebanner_manage.php?elimina=".$articolo['idart']."' >";
                echo "<img src='../img/cancella.png'  style='width: 40px; border-radius: 11px;' >". "</a>";
                echo"<a href='ebanner_manage.php?modifica=".$articolo['idart']."' style='position: relative;left: 150px;'>";
                echo '<img src="../img/modifica.png" alt="" style="width: 40px; border-radius: 11px;" >'."</a>";
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

    
    mysqli_close($conn);

?>            

        </ul>
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


    </script>

</body>
</html>