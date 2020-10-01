<?php
    session_start();
    if(isset($_POST['submit']))
    {
        if(isset($_FILES['img']) && isset($_POST['titolo']) && isset($_POST['descr']) && isset($_POST['prezzo']))
        {
            $fileTmpName=$_FILES['img']['tmp_name'];
            $img_size= getimagesize($fileTmpName); 
            if($img_size['0']<=300 || $img_size['1']<=300 )
            {
                $imge=file_get_contents($fileTmpName);
                $imge=addslashes(base64_encode($imge));
                
                if(strlen($imge)>0 && (strlen($_POST['titolo'])>0 && strlen($_POST['titolo'])<18) && strlen($_POST['descr'])>0 && strlen($_POST['prezzo'])>0 && $_POST['prezzo']>0 && $_POST['prezzo']<1001 )
                {
                    
                    $conn=mysqli_connect("localhost"," gusci","","my_gusci");
                    
                    $file=$_FILES['img'];

                    $fileName=$_FILES['img']['name'];
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
                            
                                $new_banner="insert  articoli values(null,'".addslashes($_POST['titolo'])."','".addslashes($_POST['descr'])."','".addslashes($_POST['prezzo'])."',null);";
                                mysqli_query($conn,$new_banner);
                                $new_banner_2=" update articoli set img='".addslashes($imge)."' where idart=LAST_INSERT_ID(); ";
                                mysqli_query($conn,$new_banner_2);
                                mysqli_close($conn);  
                                header("location: page_editor.php?done=1");  
                            }
                            else
                            {
                                mysqli_close($conn);
                                header("location: page_editor.php?err=1");  
                            }
                                
                        }
                        else
                        {
                            mysqli_close($conn);
                            header("location: page_editor.php?err=1");  
                        }
                            
                    }
                    else
                    {
                        mysqli_close($conn);
                        header("location:   page_editor.php?err=1");  
                    }
                        

                        

                }
                else
                {
                    if(strlen($_POST['titolo'])>=18)
                    {
                        mysqli_close($conn);
                        header("location: page_editor.php?err=2");  
                    }
                    else
                    {
                        mysqli_close($conn);
                        header("location: page_editor.php?err=1");  
                    }
    
                }
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
            header("location: page_editor.php?err=1");   
        }
    }

    if(isset($_POST['submit_2']))
    {
        if(isset($_FILES['img']) && isset($_POST['titolo']) && isset($_POST['descr']) && isset($_POST['prezzo']))
        {
            $fileTmp=$_FILES['img']['tmp_name'];   
            $img=file_get_contents($fileTmp);
            $img=(string) base64_encode($imge);
            
            if( strlen($_POST['titolo'])>0 && strlen($_POST['descr'])>0 && strlen($_POST['prezzo'])>0  && $_POST['prezzo']>0 && $_POST['prezzo']<1001)
            {
                $conn=mysqli_connect("localhost"," gusci","","my_gusci");
                if(strlen($img)<=0)
                {
                    $img=$_POST['img_old'];
                }
                mysqli_query($conn,"update articoli set titolo='".addslashes($_POST['titolo'])."' , descrizione='".addslashes($_POST['descr'])."'  , prezzo='".addslashes($_POST['prezzo'])."' , img='".addslashes($img)."'  where idart=".addslashes($_GET['modifica']).";");
                mysqli_close($conn);
                header("location: page_editor_manage.php?done=1"); 
            }
            else
            {
                mysqli_close($conn);
                header("location: ebanner_manage.php?modifica=".$_GET['modifica']."&err=1"); 
            }
        }
        else
        {
            mysqli_close($conn);
            header("location: ebanner_manage.php?modifica=".$_GET['modifica']."&err=1"); 
        }

            
    }
        
        
   
?>
