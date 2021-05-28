const UserModel = require("../Models/UserModel");
const ArtModel = require("../Models/artModel");
const axios = require('axios');
const jwt = require('jsonwebtoken');

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
    

    
    },
    signup: async (req,res)=>{
        
        if( await UserModel.signup(req.body.name,req.body.email,req.body.pwd) )
        {
            req.session.login = UserModel.getLastId();
            res.redirect("/");
        }
        else
        {
            console.log("impossibile creare user");
            res.redirect("/login");
        }

    },
    logout: (req,res)=>{
        req.session.login = false;
        res.redirect("/");
    },
    carrello: async (req,res)=>{

        const elements = await CartModel.getAllEle(req.session.login);

        console.log(elements);

        res.render("carrello",{elements: elements,data: req.session});
    },
    articoli: async (req,res)=>{
        const articles = await ArtModel.getAllArt();
        
        if(articles != -1)
            res.render("articoli",{articles: articles, data: req.session});
    },
    articolo: async (req,res)=>{
        
        const article = await ArtModel.getArtById(req.params.artId);
        const quant = await CartModel.getQuant(req.params.artId,req.session.login);

        if(article != -1)
            res.render("articolo",{article: article[0], data: req.session, quant: quant});
    },
};