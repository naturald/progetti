const Model = require("../Models/mainModel");

module.exports = {
    root: (req,res) =>{
        res.render("index",{data: req.session});   
    },
    about: (req,res) =>{
        res.render("about",{data: req.session});
    },
    carrello: (req,res) =>{
        res.render("carrello",{data: req.session});
    },
    contattaci: (req,res) =>{
        res.render("contattaci",{data: req.session});
    },
    notizie: (req,res) =>{
        res.render("notizie",{data: req.session});
    },
    loginGet: (req,res) =>{
        res.render("login",{data: req.session});
    },
    loginPost: async (req,res) =>{

        const result = await Model.login(req.body.email,req.body.pwd);

        if(result)
        {
            req.session.login = true;
            res.redirect("/");   
        }
        else
            res.redirect("/login");
    },
    logout: (req,res)=>{
        req.session.login = false;
        res.redirect("/");
    }
};