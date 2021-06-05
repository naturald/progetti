
<?php
    session_start();
    if(!isset($_SESSION['username']))
    {
        header("Location: login.php");
        exit();
    }
    else if($_SESSION['privilege'] != "admin")
    {
        header("Location: uploadData.php");
        exit();
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="/certificazioni/assets/img/avologo.png">
    <link rel="stylesheet" href="/certificazioni/assets/css/style.css">
    <title>cartificavo - Aggiugi user</title>
</head>
<body>
    <div class="body-cover"></div>

    <header>
        <img src="/certificazioni/assets/img/avologo.png">
        <img src="/certificazioni/assets/img/scritta-logo.png">
    </header>

    <div class="content-container">
        <form action="" method="POST" class="add-user-form">
            <h1>Aggiungi nuovo utente</h1>
            <div class="input-container">
                <input type="text" name="username" class="input-text" autocomplete="off" required> 
                <label for="username">Username</label>
            </div>
            <div class="input-container">
                <input type="password" name="password" class="input-text" autocomplete="off" required> 
                <label for="password">Password</label>
            </div>
            <h2>Permesso</h2>
            <div>
                <input type="radio" name="privilege" value="user" id="user" checked required>
                <label for="user">User</label>
            </div>
            <div>
                <input type="radio" name="privilege" value="admin" id="admin" required>
                <label for="admin">Adimn</label>
            </div>
            <input type="submit" name="add-user-submit" class="button">
        </form>
    </div>
</body>
</html>