var modal=document.getElementById("login");
var btn=document.getElementById("btn");
var close=document.getElementsByClassName("close")[0];
var hide2=document.getElementById("hide2");
var allert=document.getElementById("allert");
var allert2=document.getElementById("allert2");
var allert3=document.getElementById("allert3");
var tre_menu=document.getElementById("tre_menu");
var carrello=document.getElementById("carrello");
var pass=document.getElementById("pass");
var mail=document.getElementById("mail");
$(function ()
{
    
    $("#nome").blur(primLetMaglNome);
    $("#cognome").blur(primLetMaglCogn);
    $("#cognome").focus(reset_cogn);
    $("#nome").focus(reset_nom);
    $("#titolo").blur(primLetCms);
    $("#descrizione").blur(primLetCmsDesc);
    $("#nome_cms").focus(reset_cms_alt);
    $("#pass_cms").focus(reset_cms_alt);
    $("#sign_nome").focus(reset_nome_sign_up);
    $("#sign_cognome").focus(reset_cognome_sign_up);
    $("#sign_nome").blur(contr_lung_sign);
    $("#sign_cognome").blur(contr_lung_sign);
    $("#mail").blur(contr_mail);
    $("#pass").blur(contr_pass);
    $("#mail").focus(reset_mail);
    $("#pass").focus(reset_pass);


    // è normale che ci siano cosi tante varibili e function jquery?
    
    tre_menu.onclick=function()
    {

    }
    close.onclick=function()
    {
        modal.style.display="none";
        $("#nome").val("");
        $("#cognome").val("");
        allert.style.display="none";
        allert2.style.display="none";
        allert3.style.display="none";
    }
    document.getElementsByClassName("close")[1].onclick=function()
    {
        modal.style.display="none";
        $("#sign_nome").val("");
        $("#sign_cognome").val("");
        $("#mail").val("");
        $("#pass").val("");
        allert.style.display="none";
        allert2.style.display="none";
        allert3.style.display="none";
        document.getElementById("allert_sign_up").style.display="none";  
        document.getElementById("allert_sign_up2").style.display="none";  
        document.getElementById("allert_sign_up3").style.display="none";  
        document.getElementById("allert_sign_up4").style.display="none";  
    }
    btn2.onclick=function()
    {
        var nome=String($("#nome").val());
        var cognome=String($("#cognome").val());
        
        if(nome.length>10||cognome.length>10)
        {
            allert3.style.display="block";
        }
        else
        {
            if(nome.length<=0||cognome.length<=0)
            {
                if(nome.length<=0)
                {
                    allert.innerHTML="troppo corta";
                    allert.style.display="block";
                }
                if(cognome.length<=0)
                {
                    allert2.innerHTML="troppo corta";
                    allert2.style.display="block";
                }
                if(pass.length<=0)
                {
                    allert3.innerHTML="troppo corta";
                    allert3.style.display="block";
                }
                if(pass.length<=0)
                {
                    allert4.innerHTML="troppo corta";
                    allert4.style.display="block";
                }
            }
            else
            {
                    allert2.style.display="none";
                    after_login(nome,cognome);
            }
        }

       

    }
   
    hide2.onclick=function()
    {
            
    }
    
    
}
)