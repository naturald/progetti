"use strict";

//Objects
const me = {
    nome : "Marco", //propietà o attributo
    cognome : "Schiavello"
};

/*
    console.log(me.nome,me.cognome,me);// accesso statico 

    me.nome = "gino";
    me.eta = 16;

    console.log(me.nome,me.cognome,me);

    const propie = prompt("propietà:");

    if(!(propie in me))// da non fare 
        console.log("non esiste");
    else
        console.log(propie,":",me[propie]);// accesso dinamico
*/

for(let p in me)
{
    console.log(p," ",me[p]);
}

//Array
const arr = [];
console.log(arr);

const cose = [
    "boh",
    "telefono",
    {
        nome : "scrivania",
        cose : ["legna","cuffie"]
    }
];

console.log(cose[1]);

console.log(cose[2].cose.length);

arr.push(1,4,6,9);
console.log(arr);

arr.push(2);
arr.unshift(1);
console.log(arr);

const ele2 = arr.shift();
const ele = arr.pop();
console.log(arr);

const subArr = arr.slice(1,2); // [1,2)
console.log(subArr,arr);

const subArr_ = arr.splice(1,2);
console.log(subArr_,arr);

/*DOM

document.body.childNodes[];
document.body.nodeType;
document.body.removeChild();
document.body.textContent();
document.body.cloneNode();
document.body.hasChildNodes();
document.body.appendChild();
document.body.appendChild();
document.body.insertBefore(newChild,childnode);
document.body.replaceChild();
// i nodi possono avere un tipo noi usiamo quelli di tipo elemento 

//element node 
document.body.children;
document.body.querySelector();
document.body.querySelectorAll();
document.createElement();

//attributi
document.body.classList;
document.body.className;
document.body.classList.add();
document.body.classList.remove();
document.body.classList.contains();

//elements  manipulation 
document.body.innerHTML;
document.body.innerText;
document.body.outerHTML;
*/
