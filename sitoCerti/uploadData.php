<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="/certificazioni/assets/img/avologo.png">
    <link rel="stylesheet" href="/certificazioni/assets/css/style.css">
    <title>cartificavo - Upload data</title>
</head>
<body>
    <div class="body-cover"></div>

    <header>
        <img src="/certificazioni/assets/img/avologo.png">
        <img src="/certificazioni/assets/img/scritta-logo.png">
    </header>
    
    <div class="content-container">
        <form action="" method="POST" enctype="multipart/form-data" class="upload-data-form">
            <h1>Scegli tameplate certificato</h1>
            <div class="certificate-container">
                
                <div class="certificate-selection">
                    <img src="/certificazioni/assets/img/attestati/Attestato1.png">
                    <input type="radio" name="radio_certificate" value="1" required>
                </div>
                <div class="certificate-selection">
                    <img src="/certificazioni/assets/img/attestati/Attestato2.png">
                    <input type="radio" name="radio_certificate" value="2" required>
                </div>
                <div class="certificate-selection">
                    <img src="/certificazioni/assets/img/attestati/Attestato3.png">
                    <input type="radio" name="radio_certificate" value="3" required>
                </div>
            </div>

            <div class="upload-certificate">
                <button type="button" class="button" id="fakeUploadButton">Carica file csv</button>
                <h3 id="fileName"></h3>
                <input type="file" style="display: none;" accept=".csv" id="uploadButton">
            </div>

            <input type="submit" name="uploadDataSubmit" class="button">
        </form>
    </div>
    <script>
        document.querySelector("#fakeUploadButton").onclick = () =>{
            document.querySelector("#uploadButton").click();
        }
        document.querySelector("#uploadButton").addEventListener("change",() =>{
            const filepath = document.querySelector("#uploadButton").value;
            let splittedPath;
            if(filepath.indexOf("/") != -1)
                splittedPath = filepath.split("/");
            else
                splittedPath = filepath.split("\\");
            if(splittedPath[splittedPath.length-1].split(".")[1] != "csv")
            {
                document.querySelector("#uploadButton").value = "";
                return;
            }
            document.querySelector("#fileName").innerHTML = splittedPath[splittedPath.length-1];
        });
        document.querySelector(".upload-data-form").addEventListener("submit",(e) =>{
            e.preventDefault();
            if(!document.querySelector("#uploadButton").value)
            {
                console.log("ciao");
                return;
            }
            document.querySelector(".upload-data-form").submit();
        });
    </script>
</body>
</html>

