<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="/certificazioni/assets/img/avologo.png">
    <link rel="stylesheet" href="/certificazioni/assets/css/style.css">
    <title>cartificavo - Login</title>
</head>
<body>
    <div class="body-cover"></div>

    <div class="login-content">
        <form action="/certificazioni/login.php" method="POST" class="login-form">
            <img src="/certificazioni/assets/img/logo-certificavo.png" class="login-form-img">
            <div class="input-container">
                <input type="text" class="input-text" name="name" autocomplete="off" required>
                <label for="name">Nome</label>
            </div>
            <div class="input-container">
                <input type="password" class="input-text" name="password" autocomplete="off" required>
                <label for="password">Password</label>
            </div>
            <input type="submit" value="LOGIN" class="button" name="login_submit">
        </form>
    </div>
</body>
</html>

<?php
    if(isset($_POST['login_submit']))
    {
        include("connect.php");
    }
    $pdo = null;
?>