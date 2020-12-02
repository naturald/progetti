<?php
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="icon" href="img/icon.png"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gusci Sconti</title>
</head>
<body>    
    
    <link rel="stylesheet" href="css/classi.css">
    <link href="https://fonts.googleapis.com/css?family=Handlee&display=swap" rel="stylesheet">
    <header class="nav">
<?php 
    
    if(isset($_SESSION['acess']))
    {
        echo "<a id='hideCar' href='carrello.php'> ";
        echo "<img src='img/carrello.png' id='carrello' class='carrello' style='display: block;'> "."</a> ";
        echo "<div style='position:absolute;top: 20px;right:30px;'> ";
        echo "<h2 id='hide' style='font-size: 15px; position: relative; right: 40%;  width: 150px;'>".'Benvenuto,'."<br>". $_SESSION['nome']."  ".$_SESSION['cognome']."</h2> ";
        echo "</div>";
        echo "<div style='display: block; width: max-content;   margin-left: auto;  margin-right: auto;'> ";
        echo "<ul class='menu' style='display: table-cell;'> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>pag iniziale</h2></a></li> ";
        echo "<li><a href='sconti.php' style='text-decoration:none;'><h2 class='voci'>sconti</h2></a></li> ";
        echo "<li><a href='info.php' style='text-decoration:none;' ><h2 class='voci'>info</h2></a> </li> ";
        echo "<li><a href='session_destroy.php' id='SesD' style='text-decoration:none;'><h2 class='voci_hide' style='display: block;' id='hide2'>logout</h2></a></li>"."</ul> ";
        echo <<<'EOT'
        </div>
        <h1 class="titNav" id="titNav" >
            GUSCI
        </h1>

        <button onclick="dropDownL()" class="DropL" id="DropL">  
            <span class="tre"></span>
            <span class="tre"></span>
            <span class="tre" style="margin-bottom: 0;"></span>
        </button>
        
        
        <div id="cont_dropL" class="cont_dropL" style="top:-15px;">
            <ul class="lista_cont_dropL">
EOT;
                echo '<li class="voci_cont_dropL" style="height: fit-content;">Benvevenuto<br>'. $_SESSION['nome'].'  '.$_SESSION['cognome'].'</li>';
echo <<<'EOT'
                <li class="voci_cont_dropL"><a href="index.php" class="text_voci_cont_dropL">Pag iniziale</a></li>
                <li class="voci_cont_dropL"><a href="sconti.php"  class="text_voci_cont_dropL">Sconti</a></li>
                <li class="voci_cont_dropL"><a href="info.php"  class="text_voci_cont_dropL">Info</a></li>
                <li class="voci_cont_dropL"><a href="carrello.php"  class="text_voci_cont_dropL">Carrello</a></li>
                <li class="voci_cont_dropL" style="border: none;"><a href="session_destroy.php" class="text_voci_cont_dropL">Logout</a></li>
            </ul>
        </div>
       
EOT;
                                
    }
    else
    {
        echo "<div style='position:absolute;top: 20px;right:30px;'>";
        echo "<button class='bottoni' id='btn'  onclick='login()' > ";
        echo "<h2 style='font-size: 18px;' >"."Login"."</h2>";            
        echo "</button> ";
        echo "</div> ";
        echo "<div style='display: block; width: max-content;  margin-left: auto;  margin-right: auto;'> ";
        echo "<ul class='menu' style='display: table-cell;'> ";
        echo "<li><a href='index.php' style='text-decoration:none;'><h2 class='voci'>pag iniziale</h2></a></li> ";
        echo "<li><a href='sconti.php' style='text-decoration:none;'><h2 class='voci'>sconti</h2></a></li> ";
        echo "<li><a href='info.php' style='text-decoration:none;' ><h2 class='voci'>info</h2></a> </li> "."</ul>";
        echo <<<'EOT'
        </div>
        <h1 class="titNav" id="titNav" >
            GUSCI
        </h1>
        <button onclick="dropDownL_Prelog()" class="DropL" id="DropL">  
            <span class="tre"></span>
            <span class="tre"></span>
            <span class="tre" style="margin-bottom: 0;"></span>
        </button>
            
        <div id="cont_dropL" class="cont_dropL" style="top:-15px;">
            <ul class="lista_cont_dropL">
                <li class="voci_cont_dropL"><a href="index.php" class="text_voci_cont_dropL">Pag iniziale</a></li>
                <li class="voci_cont_dropL"><a href="sconti.php"  class="text_voci_cont_dropL">Sconti</a></li>
                <li class="voci_cont_dropL"><a href="info.php"  class="text_voci_cont_dropL">Info</a></li>
                <li class="voci_cont_dropL" style="border: none;"><h2 class="text_voci_cont_dropL" id="voce_login_drop" onclick="dropDownL_login()" >Login</h2></li>
            </ul>
        </div>
EOT;
    }

    
  

?>
       
        
        <a href="index.php">
            <img src="img/logo_sito.png" alt="" class="img_logo">
        </a>
        
      
        
        <button onclick="dropDownL_close()" class="DropL" style="display: none;" id="DropL_close">  
            <div style="width: 30px; height: 30px; position: relative; top: 10px;">
                <span style="transform: rotate(-45deg);height: 6px; width: 30px; background-color: white;display: block;"></span>
                <span style="transform: rotate(45deg);position: relative;height: 6px; width: 30px; background-color: white;display: block;top: -5px;"></span>
            </div>
        </button>

       
    </header>


    
   <div class="cover">
        <div class="cover-opacita"></div>
        <div class="cover2">
            <div class="cover_text">
                <h1 class="titolo">
                    GUSCI
                </h1>
                <h2>
                    Sconti
                </h2>
                <br>
                <div style="width: 80%;margin:auto">
                    <h2>
                        Gli sconti finiscono il
<?php
                        $conn=mysqli_connect("localhost"," gusci","","my_gusci");
                        $articoli=mysqli_query($conn,"select expiration from articoli where sconto>0;");
                        $articoli=mysqli_fetch_array($articoli);
                        echo "<span id='ex_date'>1/".$articoli[0]."</span>";

?>  
                        mancano ancora
                    </h2>
                </div>
                <br>
                <h1 id="time"></h1>
            </div>
        </div>
    </div>

    <input type="text" class="lente" onkeyup="trova_art()" id="lente" style="background-image: url(img/searchicon.png);" placeholder=" cerca articolo">


    <div class="card">
        <ul class="cardList" id="lista">


<?php


    $articoli=mysqli_query($conn,"select * from articoli where sconto>0;");

    foreach($articoli as $articolo)
    {
        echo "<li id='banner'>";
            echo "  <a href='tameplate_banner.php?articolo=".$articolo['idart']."' style='text-decoration: none;color: black;'>";
            echo "<div class='banner'>";
            if($articolo['sconto']>1)
            {
                echo " <img src='img/".$articolo['sconto']."sconto.png' style='position: absolute; height: 100px;'>";           
            }
                echo " <center>";
                        echo "<img class='img_banner' src='data:image;base64,".$articolo['img']."'  >";
                    echo " <div>";
                        echo " <h1 class='text_banner'>";
                            echo $articolo['titolo'];
                        echo "</h1><br>";
                        if($articolo['sconto']>1)
                        {
                            echo "<del class='text_banner'>";
                            echo $articolo['prezzo']." &#x20ac";
                            echo "</del><br>";
                            echo "<h3 class='text_banner'>";
                            $prezzo=floor($articolo['prezzo']-(($articolo['prezzo']*$articolo['sconto'])/100));
                            echo $prezzo." &#x20ac";
                            echo "</h3>";
                        }
                        else
                        {
                            echo "<h3 class='text_banner'>";
                            echo $articolo['prezzo']." &#x20ac";
                            echo "</h3>";
                        }
                    echo " </div>";
                    
                echo "</center>";
            echo "</div>";
            echo "</a>";
        echo "</li>";

    
    }
    mysqli_close($conn);
?>            

        </ul>
    </div>
    
    <div id="login_regiser">

    </div>  
    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    <script>
        setInterval(()=>{
        var ex_time=document.getElementById("ex_date").innerHTML.split("/");
        var time=document.getElementById("time");
        var now=new Date();
        if(now.getMonth()==12)
        {
            now.setFullYear(now.getFullYear()+1);
            now.setMonth(1);
        }
        else
            now.setMonth(now.getMonth()+1);
            
        var sec=new Date(ex_time[2],ex_time[1],ex_time[0]).getTime()-(now.getTime());
        var days = Math.floor(sec / (1000 * 60 * 60 * 24));
        var hours = Math.floor((sec % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
        var minutes = Math.floor((sec % (1000 * 60 * 60)) / (1000 * 60));
        var seconds = Math.floor((sec % (1000 * 60)) / 1000);
        time.innerHTML=days+" "+hours+" "+minutes+" "+seconds ;
        }
        ,1000);

    </script>
</body>
</html>