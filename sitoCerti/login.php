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
        require_once "connect.php";
        $name = mysqli_real_escape_string($conn,$_POST['name']);
        $password = mysqli_real_escape_string($conn,$_POST['password']);
        $query = mysqli_query($conn,"SELECT name,privilege,salt FROM users WHERE name = '".$name."';");
        $rows = mysqli_num_rows($query);
        if($rows == 1)
        {
            $user = mysqli_fetch_assoc($query);
            $password += $user["salt"];
            if(password_verify($password, $user["password"]))
            {
                session_start();
                $_SESSION['username'] = $user["name"];
                $_SESSION['privilege'] = $user["privilege"];
                header("Location: upload_data.php");
                exit();
            }
            else
            {
                header("Location: login.php");
                exit();
            }
            
        }
    }
    
?>