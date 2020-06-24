<?php
    session_start();
    if(isset($_POST['submit']))
    {
        
        $conn=mysqli_connect("localhost"," gusci","","my_gusci");
        
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
                
                    $imge=file_get_contents($fileTmpName);
                    $imge=addslashes(base64_encode($imge));


                    $new_banner="insert  articoli values(null,'".addslashes($_POST['titolo'])."','".addslashes($_POST['descr'])."','".addslashes($_POST['prezzo'])."','".$imge."');";
                    mysqli_query($conn,$new_banner);
                    mysqli_close($conn);
                    header("location: page_editor.php?done=1");  
                }
                else
                {
                    mysqli_close($conn);
                    header("location: page_editor.php?err=3");  
                }
                    
            }
            else
            {
                mysqli_close($conn);
                header("location: page_editor.php?err=2");  
            }
                
        }
        else
        {
        
            mysqli_close($conn);
            header("location: page_editor.php?err=1");  
        }
            

            

    }

    if(isset($_POST['submit_2']))
    {
        $conn=mysqli_connect("localhost"," gusci","","my_gusci");

        
        $fileTmp=$_FILES['img']['tmp_name'];   
        $imge=file_get_contents($fileTmp);
        $img=(string) base64_encode($imge);
        if(strlen($img)<=0)
        {
            $img=$_POST['img_old'];
        }
        
      
        

        mysqli_query($conn,"update articoli set titolo='".addslashes($_POST['titolo'])."' , descrizione='".addslashes($_POST['descr'])."'  , prezzo='".addslashes($_POST['prezzo'])."' , img='".addslashes($img)."'  where idart=".addslashes($_GET['modifica']).";");
        mysqli_close($conn);
        header("location: page_editor_manage.php?done=1"); 
            
    }
?>
