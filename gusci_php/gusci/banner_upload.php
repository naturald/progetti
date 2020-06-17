<?php 
    if(isset($_POST['submit']))
    {
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
                    $fileNameNew= uniqid('', true ).'.'.$fileActualExt;
                    $fileDestination= 'uploads/'.$fileNameNew;
                    move_uploaded_file( $fileTmpName,$fileDestination );
                    echo "fatto";
                }
                else
                    echo "è troppo pesante ";
            }
            else
                echo "c'è stato un errore";
        }
        else
            echo "tipo non supportato";
        

    }
?>