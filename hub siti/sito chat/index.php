<?php
    session_start();
    if(!$_SESSION['log'])
        header("location: login.php");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/class.css">
    <title>sito live chat</title>
</head>
<body style="display:flex;flex-direction:column;justify-content:center;">
    <h1 style="margin: auto;">Ciao <?php echo $_SESSION['name']?></h1>
    <div style="width: 80%;height:80%;margin:auto;margin-top:-20px">
        <div style="height: 80%;box-shadow: 0px 0px 20px -5px;padding:10px;border-radius:20px;overflow:scroll" id="ajax_up">

        </div>
        <div  style="height:20%;display:flex;flex-direction:column;justify-content:center">
            <form action="send.php" method="POST" style="height: max-content;width: 70%;margin:auto">
                <input type="text" class="message" name="message" required>
                <input type="submit" value="Invia" class="send" name="sub_msg">
            </form>
        </div>
    </div>
    <script type="text/javascript">

        var ajax=new XMLHttpRequest();
        ajax.open("GET","chat.php",false);
        ajax.send(null);
        document.getElementById("ajax_up").innerHTML=ajax.responseText;
        
        setInterval(function() 
        {
            var ajax=new XMLHttpRequest();
            ajax.open("GET","foo.php",false);
            ajax.send(null);
            document.getElementById("ajax_up").innerHTML=ajax.responseText;
            
        }, 1000);
    </script>
</body>
</html>
