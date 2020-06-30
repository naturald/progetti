<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
        
        <link rel="stylesheet" href="css/classi.css">
        <div id="login" class="modal" style="display: flex;">
            <div id="con_login" class="con_modal" > 
                <span class="close">&times;</span>
                <form name="sign_up" action="elogin.php?auten=1" method="POST">
                    <center>
                        <img src="img/logo_sito.png" style="height: 125px;width: 125px;">
                        <h1 style="padding-bottom: 40px;
                                font-size: 50px;
                                font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;">
                                GUSCI LOGIN </h1>
                        <input type="text" class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung()" id="nome" name="nome" placeholder="Nome">
                    </center>
                    

                    <center>
                        <input type="password"  class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung()" id="psw" name="psw"  placeholder="password">
                    </center>
                        
                    <center style="    margin-top: 50px;">
                        

                        <input type="submit" class="bottoni"  id="btn2" value="login"  style="padding: 13px 33px 13px 33px;
                                                                                            margin-top: 25px;
                                                                                            margin-bottom: 20px;
                                                                                            font-size: 15px;">
                    
                        <h5 id="sign_up">non ho un account</h5>
                        <h6  class="hide" style="color: red;position: relative; top: -130px;" id="allert3">nome o password sono sbagliati</h6>

                    </center>
                </form>
            </div>
            
            <div id="con_sign_up" class="con_modal_sign_in" > 
                <span class="close">&times;</span>
                <form name="sign_up" action="elogin.php?auten=2" method="POST">
                    <center>
                        <img src="img/logo_sito.png" style="height: 125px;width: 125px;">
                        <h1 style="padding-bottom: 40px;
                                font-size: 50px;
                                font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;">
                                GUSCI REGISTRAZIONE </h1>
                        <input type="text" class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung_sign()" id="sign_nome" name="sign_nome" placeholder="Nome">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up">troppo lunga</h6><br>
                    <center>
                        <input type="text"  class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung_sign()" id="sign_cognome" name="sign_cognome"  placeholder="Cognome">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up2">troppo lunga</h6><br>
                    <center>
                        <input type="mail"  class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung_sign()" id="mail" name="mail" placeholder="Mail">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up3">non e una mail</h6><br>
                    <center>
                        <input type="password"  class="dati" style="margin-bottom: 20px;" onkeyup="contr_lung_sign()" id="pass" name="pass" placeholder="Password">
                    </center>
                    <h6 class="hide allert" id="allert_sign_up4">troppo lungha</h6><br>
                    <center>
                        <input type="submit" class="bottoni" id="btn2_sign"  onclick="after_sign_up(sign_nome,sign_cognome)"  style="padding: 13px 33px 13px 33px;
                                                                                                                                    margin-top: 25px;
                                                                                                                                    margin-bottom: 20px;
                                                                                                                                    font-size: 15px;    
                                                                                                                                    top: -25px;
                                                                                                                                    position: relative;">
                        

                        <h5 onclick="switch_modal()" style="position: relative;top:-15px;">ho gia un account</h5>

                    </center>
                </form>
            </div>
        </div> 

    <script type="text/javascript" src="js/jquery-3.4.1.min.js"></script>
    <script type="text/javascript" src="js/libreria.js"></script>
    <script type="text/javascript" src="js/codice.js"></script>
    <script>
        var modal=document.getElementById("login");
        document.getElementById("sign_up").onclick=function()
        {
            document.getElementById("con_login").style.display="none";
            document.getElementById("con_sign_up").style.display="block";
            document.getElementById("sign_up").style.display="none";
            spazzino();

        }
        
        window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
     
    }
    </script>
</body>
</html>

        
        