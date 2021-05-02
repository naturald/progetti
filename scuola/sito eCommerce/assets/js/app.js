"use strict";

document.getElementById("menu_nav").onclick = () =>{
    if(document.getElementsByClassName("voci_nav")[0].style.height == "fit-content")
    {
        document.getElementsByClassName("voci_nav")[0].style.height="0px";
        document.getElementById("arrow_nav").style.transform="translate(-50%,-50%) rotate(0deg)";
    }
    else
    {
        document.getElementsByClassName("voci_nav")[0].style.height="fit-content";
        document.getElementById("arrow_nav").style.transform="translate(-50%,-50%) rotate(180deg)";
    }
}

respoNav();

window.addEventListener('resize',(e) =>{
    respoNav();

});


function respoNav()
{
    if(window.innerWidth > 1100)
    {
        document.getElementsByClassName("voci_nav")[0].style.height="0px";
        document.getElementById("arrow_nav").style.transform="translate(-50%,-50%) rotate(0deg)";
    }
    
    const dropDowns = document.getElementsByClassName("dropdown_content");
    for(let i = 0;i<dropDowns.length;i++)
    {
        if(window.innerWidth <= 1100)
        {
            dropDowns[i].style.height = "0px";
            dropDowns[i].style.marginTop= "0px";
            const prevEle = dropDowns[i].previousElementSibling;
            prevEle.href="#";
            dropDowns[i].parentElement.onclick = () => {
      
                if(dropDowns[i].style.height != "max-content")
                {
                    dropDowns[i].style.height = "max-content";
                    dropDowns[i].style.marginTop = "10px";
                }
                else
                {
                    dropDowns[i].style.height = "0px";
                    dropDowns[i].style.marginTop = "0px";
                }
                
            }
        }
        else
        {
            dropDowns[i].style.marginTop = "0";
            dropDowns[i].style.height = "max-content";
            const prevEle = dropDowns[i].previousElementSibling;
            prevEle.href= dropDowns[i].querySelector('a').href;
        }
        
    }
}