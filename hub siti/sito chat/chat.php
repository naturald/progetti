<?php
    $conn=mysqli_connect("sql206.epizy.com","epiz_26875194","KQLnoUAgB9B","epiz_26875194_hub_siti");
    $content=mysqli_query($conn,"select * from chat;");
    //$content=mysqli_fetch_array($content);
    //$content=array_reverse($content);
    foreach ($content as $element)
    {
        echo "<div class='box_msg'>";
            echo " <h3 style=' margin-top: 5px;margin-bottom: 5px;'> ".$element['user']."</h3><br>";
            echo " <p class='msg'>".$element['text']."</p><br>";
        echo "</div>";
    }
    mysqli_close($conn);
?>