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


            if(isset($_GET['camb_quant_su']))
            {
                $quantita=mysqli_query($conn,"select * from carrello where idart=".addslashes($_GET['camb_quant_su'])." and iduser=".addslashes($_SESSION['iduser']).";");
                $quantita=mysqli_fetch_assoc($quantita);
                if($quantita['quantita']<10)
                {
                    $i=$quantita['quantita']+1;
                    mysqli_query($conn,"update carrello set quantita=$i where idart=".addslashes($_GET['camb_quant_su'])." and iduser=".addslashes($_SESSION['iduser']).";");  
                }
            }

            if(isset($_GET['camb_quant_giu']))
            {
                $quantita=mysqli_query($conn,"select * from carrello where idart=".addslashes($_GET['camb_quant_giu'])." and iduser=".addslashes($_SESSION['iduser']).";");
                $quantita=mysqli_fetch_assoc($quantita);
                if($quantita['quantita']!=1)
                {
                    $i=$quantita['quantita']-1;
                    mysqli_query($conn,"update carrello set quantita=$i where idart=".addslashes($_GET['camb_quant_giu'])." and iduser=".addslashes($_SESSION['iduser']).";");  
                }
                
            }

            if(isset($_GET['cart_elimina']))
            {   
                mysqli_query($conn,"delete from carrello where idart=".addslashes($_GET['cart_elimina'])." and iduser=".addslashes($_SESSION['iduser']).";");
            }
               

            $articoli_sel=mysqli_query($conn,"select * from carrello where iduser=".addslashes($_SESSION['iduser']).";");

            foreach($articoli_sel as $articolo_sel)
            {    
                $articolo=mysqli_query($conn,"select * from articoli where idart=".addslashes($articolo_sel['idart']).";");
                $articolo=mysqli_fetch_assoc( $articolo);
                if(strlen($articolo['idart'])<=0)
                    mysqli_query($conn,"delete from carrello where idart=".addslashes($articolo_sel['idart'])." and iduser=".addslashes($_SESSION['iduser']).";");
                else
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
                    echo "<a href='carrello.php?cart_elimina=".$articolo_sel['idart']."' >";
                    echo '<img src="img/cancella.png" alt="" style="position: absolute;right: 10px; height:40px; border-radius: 10px;">'. "</a>";
                    echo '<h3 style="position: absolute; right: 70px; bottom: 30px; width: fit-content;">Quantità:</h3>';
                    echo '<h3 style="position: absolute; bottom: 30px; right: 50px;">'.$articolo_sel['quantita'].'</h3> ';
                    echo "<a href='carrello.php?camb_quant_su=".$articolo_sel['idart']."' >";
                    echo '<img src="img/freccia_su.png" alt="" style="position: absolute;right: 10px; bottom: 45px ; height:30px; border-radius: 10px;">'. "</a>";
                    echo "<a href='carrello.php?camb_quant_giu=".$articolo_sel['idart']."' >";
                    echo '<img src="img/freccia_giu.png" alt="" style="position: absolute;right: 10px; bottom: 10px ; height:30px; border-radius: 10px;">'. "</a>";
                    echo '</div>';
                    $prezzo_tot=$prezzo_tot+($articolo['prezzo']*$articolo_sel['quantita']);
                }

                
            }


            mysqli_close($conn);
?> 

        </div>
        <h1 style="position:relative;top:20px;left:10%;width: fit-content;">Prezzo totale: <?php echo $prezzo_tot ?> &#x20ac</h1>
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