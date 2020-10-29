function menu()
{
    document.getElementById("menu").style.display="flex";
}
function close_menu()
{
    document.getElementById("menu").style.display="none";
}
function color(input)
{
    document.getElementById("text").style.color="#"+input;
    console.log(input);
}
function font_size(input)
{
    document.getElementById("text").style.fontSize=input+"px";
}
function font_family(input)
{
    document.getElementById("text").style.fontFamily=input;
}
function text_align(input)
{
    document.getElementById("text").style.textAlign=input;
}
function back_col(input)
{
    document.getElementById("text").style.backgroundColor="#"+input;
}
function border(input)
{
    document.getElementById("text").style.border=input;
}
function padding(input)
{
    document.getElementById("text").style.padding=input+"px";
}
function margin(input)
{
    document.getElementById("text").style.margin=input+"px";
}
function submit()
{
    close_menu();
    color(String(document.getElementById("color").value));
    font_size(String(document.getElementById("font_size").value));
    font_family(String(document.getElementById("font_family").value));
    text_align(String(document.getElementById("text_align").value));
    back_col(String(document.getElementById("back_col").value));
    border(String(document.getElementById("border").value));
    padding(String(document.getElementById("padding").value));
    margin(String(document.getElementById("margin").value));
}