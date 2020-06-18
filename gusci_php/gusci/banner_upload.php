<?php
    session_start();
    if(isset($_POST['submit']))
    {
        
        $conn=mysqli_connect("localhost","visitor","casa","gusci");
        
        $file=$_FILES['img'];

        $fileName=$_FILES['img']['name'];
        $fileTmpName=$_FILES['img']['tmp_name'];
        $fileSize=$_FILES['img']['size'];
        $fileError=$_FILES['img']['error'];
        $fileType=$_FILES['img']['type'];

        $fileExt=explode('.',$fileName);
        $fileActualExt=strtolower(end($fileExt));

        $allowed= array('jpg','png','jpeg','pdf');

        if(in_array($fileActualExt, $allowed ))
        {
            if($fileError === 0)
            {
                if($fileSize<1000000)
                {
                    //$get_idart="select idart from articoli where titolo ='".$_POST['titolo']."';";
                    //$get_idart_Q=mysqli_query($conn,$get_idart);
                    //$get_idart_A=mysqli_fetch_assoc($get_idart_Q);
                    //$fileNameNew= $get_idart_A['idart'].'.'.$fileActualExt;
                    
                    //move_uploaded_file( $fileTmpName,$fileDestination );
                    $imge=file_get_contents($fileTmpName);
                    $imge=addslashes(base64_encode($imge));


                    $new_banner="insert  articoli values(null,'".$_POST['titolo']."','".$_POST['descr']."','".$_POST['prezzo']."','".$imge."');";
                    mysqli_query($conn,$new_banner);
                
                    header("location: page_editor.php?done=1");  
                }
                else
                    header("location: page_editor.php?err=3");  
            }
            else
                header("location: page_editor.php?err=2");  
        }
        else
            header("location: page_editor.php?err=1");  

            

    }
?>
