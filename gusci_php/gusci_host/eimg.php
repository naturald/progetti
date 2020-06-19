<?php
    session_start();
    
    $conn=mysqli_connect("sql304.epizy.com","epiz_26047184","OoRpFIA6OPJp4CU","epiz_26047184_gusci");
    
    $id=$_REQUEST['id'];



    $img_q=mysqli_query($conn,"select * from articoli where idart=".$id.";");
    $img1=mysqli_fetch_assoc($img_q);
    $img2=$img1['img'];

    header("Content-type: image/jpeg");

    echo $img2;
?>