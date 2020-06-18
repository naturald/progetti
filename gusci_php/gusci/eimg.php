<?php
    session_start();
    
    $conn=mysqli_connect("localhost","visitor","casa","gusci");
    
    $id=$_REQUEST['id'];

    $_SESSION['foo']=$id;

    $img_q=mysqli_query($conn,"select * from articoli where idart=".$id.";");
    $img1=mysqli_fetch_assoc($img_q);
    $img2=$img1['img'];

    header("Content-type: image/jpeg");

    echo $img2;
?>