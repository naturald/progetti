"use strict"

const todo_list = document.getElementsByClassName("todo-list")[0];
const li_templ = document.querySelector(".todo-list > li");
todo_list.innerHTML = "";
const id = 0; 

document.querySelector("button").onclick = evt => {
    evt.preventDefault();
    submit();
};  

const item = [];

function createItem(id,name)
{
    item.push(
        {
            id: id,
            name : name,
            checked : false
        }
    );
    id++;
}

function renderList(ul,items)
{
    todo_list.innerHTML = "";
    items.forEach(element => {
        if(element.checked)
            return;
        const li = li_templ.cloneNode(true);
        li.querySelector("span").innerHTML = element.name;
        li.querySelector("input").onclick = () => {
            element.checked = true;
            li.querySelector("input").checked = true;
            li.querySelector("input").disabled = true;
            li.classList.add("done");
            setTimeout(() =>{ li.remove() }, 500);
        }
        ul.appendChild(li);
    });
}

function submit()
{
    if(! document.querySelector("input").value)
        return;
    createItem(id, document.querySelector("input").value);

    renderList(todo_list,item);

    document.querySelector("input").value = "";
/*
    const list_item = document.createElement("li");
    list_item.className = "todo-list";
    const item_input = document.createElement("input");
    item_input.type = "checkbox";
    item_input.className = "todo-list-item-done";

    const item_span = document.createElement("span");
    item_span.className = "todo-list-item-description";
    item_span.innerHTML = li_templ.querySelector(".todo-list-item-description").textContent;
    
    list_item.appendChild(item_input);
    list_item.appendChild(item_span);
    todo_list.appendChild(list_item);
*/
    console.log(item);
}