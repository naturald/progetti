"use strict";

//-----------funzioni------------
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

function displayCart()
{
    const cart = document.querySelector("#cart");
    const tameplate = document.querySelector(".cart_ele");
    for(let i = 0;i<localStorage.length;i++)
    {
        const tmp = tameplate.cloneNode(true);
        const dataEleFileds = tmp.children;
        const dataEle = JSON.parse(localStorage.getItem(localStorage.key(i)));
        
        dataEleFileds[0].src = dataEle.img;
        dataEleFileds[1].innerHTML = localStorage.key(i);
        dataEleFileds[2].innerHTML  = dataEle.price + "€";
        dataEleFileds[3].querySelector(".cart_ele_quanti").innerHTML  = dataEle.quant;

        cart.appendChild(tmp);
    }

}

function setDeleteBtn()
{
    document.querySelectorAll(".cart_ele span").forEach(ele => {
        ele.onclick = () =>{
            localStorage.removeItem(ele.parentElement.querySelector(".cart_ele_name").innerHTML);
            location.reload();
            getTot();
        }
    }); 
}

function setDecBtn()
{
    document.querySelectorAll(".cart_sele_quanti :last-child").forEach(ele => {
        ele.onclick  = () =>{
            const nameEle = ele.parentElement.parentElement.querySelector(".cart_ele_name").innerHTML;
            const eleObj = JSON.parse(localStorage.getItem(nameEle));
            if(eleObj != null && eleObj.quant > 1)
            {
                eleObj.quant--;
                localStorage[nameEle] = JSON.stringify(eleObj);
                ele.parentElement.parentElement.querySelector(".cart_ele_quanti").innerHTML = eleObj.quant;
            }
            getTot();
        }
    });
}

function setAddBtn()
{
    document.querySelectorAll(".cart_sele_quanti :first-child").forEach(ele => {
        ele.onclick  = () =>{
            const nameEle = ele.parentElement.parentElement.querySelector(".cart_ele_name").innerHTML;
            const eleObj = JSON.parse(localStorage.getItem(nameEle));
            if(eleObj != null && eleObj.quant < 10)
            {
                eleObj.quant++;
                localStorage[nameEle] = JSON.stringify(eleObj);
                ele.parentElement.parentElement.querySelector(".cart_ele_quanti").innerHTML = eleObj.quant;
            }
            getTot();
        }
    });
    
}

function cart()
{
    displayCart();

    setDeleteBtn();

    setAddBtn();

    setDecBtn();

    getTot();
}

function alreadyExiEle(name)
{
    if(localStorage.getItem(name) != null)
        return true;
    return false;
}

function addArti(img,name,price,quant = 1)
{
    if(!alreadyExiEle(name))
    {
        localStorage.setItem(name,JSON.stringify({
            img: img,
            price: price,
            quant: quant
        }));
    }
    else
    {
        const ele = JSON.parse(localStorage.getItem(name));
        if(ele.quant == 10)
            return;
        ele.quant++;
        localStorage[name] = JSON.stringify(ele);
        quant = ele.quant;
    }
    return quant;
}

function clearStorage()
{
    localStorage.clear();
}

function displayQuantEle()
{
    const eleObj = JSON.parse(localStorage.getItem(document.querySelector("#title_pag_article").innerHTML));
    const ele = document.querySelector("#buy_pag_article > h5");
    if(eleObj.quant)
    {
        ele.innerHTML = "Nel Carrello: " + eleObj.quant;
        ele.style.display = "block";
    }

        
}

function getTot()
{
    let totPrice = 0;
    for(let i = 0;i<localStorage.length;i++)
    {
        const dataEle = JSON.parse(localStorage.getItem(localStorage.key(i)));
    
        totPrice += (dataEle.price * dataEle.quant);
    }

    document.querySelector("#buy_cart > h3").innerHTML = totPrice + "€";
}

//---------------------------------

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

document.querySelectorAll("#buy_pag_article > button").forEach(ele => {
    ele.onclick = () =>{
        const data = document.querySelector("#data_pag_article");
        let img = data.previousElementSibling.src;
        let name = data.querySelectorAll("div")[0].children[0].innerHTML;
        let price = data.querySelectorAll("div")[1].children[0].innerHTML.split(" ")[1];

        let nArti = addArti(img,name,price);
        if(!nArti)
            nArti = 10;

        document.querySelector("#buy_pag_article > h5").innerHTML = "Nel Carrello: " + nArti;
        document.querySelector("#buy_pag_article > h5").style.display = "block";
    }   
});

document.querySelector("#buy_cart > h5").onclick = () =>{
    clearStorage();
    location.reload();
};



