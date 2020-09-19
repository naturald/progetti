<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>immagini</title>
</head>
<body>
    <link rel="stylesheet" href="style.css">
    <form action="upload.php"  method="POST" enctype="multipart/form-data" style="margin: auto; width: fit-content; position: relative; top: 750px;margin-bottom:70px ">
        <div style="display: flex;">
            <input type="text" name="titolo"  class="dati" style="margin-right: 15px; padding: 12px;" placeholder="Titolo">
            <input type="file" class="file" name="img">
        </div>
        <input type="number" min="1" name="idimg" placeholder="Id img" class="dati">
        <div style="display: flex;">
        <input type="submit" name="fatto" class="submit" value="carica">
<?php
    if(strlen($_GET['idimg'])>0)
    {
        echo '<button type="button" onclick="Rotate()"  class="submit" style="    margin-left: -80px;" >ruota</button>';
    }
?>      
        </div>
    </form>
    
   
<?php
    if(strlen($_GET['idimg'])>0)
    {
        $conn=mysqli_connect("sql307.epizy.com","epiz_26750268","jPLe47x82QqPV","epiz_26750268_immagini");
        $query_text="select img from immagine where idimg='".$_GET['idimg']."';";
        $query=mysqli_query($conn,$query_text);
        $img=mysqli_fetch_array($query);
        echo "<a href='".$img[0]."' onclick='download('".$img[0]."')'  class='link' id='link' download>";

        echo "<img  src='".$img[0]."' class='img' id='img' style=' transform: rotate(0deg);''>";
        

        echo "</a>"; 
    }

    
    $conn=mysqli_connect("sql307.epizy.com","epiz_26750268","jPLe47x82QqPV","epiz_26750268_immagini");
    $tutte_img=mysqli_query($conn,"select * from immagine;");
    echo "<ul style='color: white; width: fit-content; margin-left: 3%;position: absolute;top: 835px;'>";
    foreach($tutte_img as $immagine)
    {
        echo "<li>".$immagine['idimg']." ".$immagine['titolo']."</li>";
    }
    
    echo "</ul>";

    mysqli_close($conn);
    
?>

    <script>
        var volte_click=1;
        function Rotate()
        {
            var deg=90*volte_click;
            document.getElementsByClassName("img")[0].style.transform = "rotate("+deg+"deg)";
            if(volte_click>=4)
                volte_click=1;
            else
                volte_click++;
        }
  
    </script>


</body>
</html>