<?php
     session_start();
    if(isset($_POST['sub_msg']))
    {
        $conn=mysqli_connect("sql206.epizy.com","epiz_26875194","KQLnoUAgB9B","epiz_26875194_hub_siti");
        mysqli_query($conn,"insert into chat values(null,'".$_POST['message']."','".$_SESSION['name']."');");
        mysqli_close($conn);
    }
    header("location: index.php");
?>