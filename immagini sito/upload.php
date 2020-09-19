<?php

    if(isset($_POST['fatto']))
    {
        
        $fileSize=$_FILES['img']['size'];
        if($fileSize>0)
        {
            $conn=mysqli_connect("sql307.epizy.com","epiz_26750268","jPLe47x82QqPV","epiz_26750268_immagini");

            $fileTmpName=$_FILES['img']['tmp_name'];
            $fileName=$_FILES['img']['name'];
            $casa=move_uploaded_file($fileTmpName,"img/$fileName");
            //$imge=file_get_contents($fileTmpName);
            //$imge=addslashes(base64_encode($imge));
            $query="insert immagine values(null,'".$_POST['titolo']."','img/".$fileName."');";
            mysqli_query($conn,$query);

            
            mysqli_close($conn);

            header("location: index.php?status=true"); 
        }
        header("location: index.php?status=true&idimg=".$_POST['idimg']); 
    }
    else
    {
        header("location: index.php"); 
    }

?>