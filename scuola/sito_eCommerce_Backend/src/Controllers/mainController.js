const jwt = require('jsonwebtoken');
const { default: axios } = require("axios");

module.exports = {
    root: (req,res) =>{
        res.render("index",{data: {login: req.userId} });   
    },
    about: (req,res) =>{
        res.render("about",{data: {login: req.userId} });
    },
    contattaci: (req,res) =>{
        res.render("contattaci",{data: {login: req.userId} });
    },
    notizie: (req,res) =>{
        res.render("notizie",{data: {login: req.userId} });
    },
    loginGet: (req,res) =>{
        res.render("login");
    },
    logout: (req,res)=>{
        res.setHeader('set-cookie', 'token=; max-age=0');
        res.redirect("/");
    },
    carrello: async (req,res)=>{
        const cartId = await axios.get("http://localhost:3000/api/carts/last/users/"+req.userId+"?auth="+req.token).catch(err => console.log(err) );
        const elements = await axios.get("http://localhost:3000/api/carts/"+cartId.data+"/articles?auth="+req.token).catch(err => console.log(err) );
        
        res.render("carrello",{elements: elements.data, data: {login: req.userId,cartId: cartId.data,auth: req.token}});
    },
    articoli: async (req,res)=>{

        const articles = await axios.get("http://localhost:3000/api/articles").catch(err => console.log(err) );

        if(articles.data != -1)
            res.render("articoli",{articles: articles.data, data: {login: req.userId} });
    },
    articolo: async (req,res)=>{
        
        const article = await axios.get("http://localhost:3000/api/articles/"+req.params.artId).catch(err => console.log(err) );
        const cartId = await axios.get("http://localhost:3000/api/carts/last/users/"+req.userId+"?auth="+req.token).catch(err => console.log(err) );
        const quant = await axios.get("http://localhost:3000/api/carts/"+cartId.data+"/articles/"+req.params.artId+"?auth="+req.token).catch(err => console.log(err) );


        if(article != -1)
            res.render("articolo",{article: article.data, data: {login: req.userId,cartId: cartId.data,quant: quant.data.quant,auth: req.token } });
    },
    gallery:(req,res) =>{
        res.render("gallery",{data: {login: req.userId} });   
    },
    authToken: (req,res,next) =>{ //midleware
        
        let token = null;

        if(req.headers.cookie)
            req.headers.cookie.split(';').forEach(element => {
                if(element.indexOf("token=") != -1)
                    token = element.split("=")[1];
            });

        if(!token)
        {
            if(req.route.path == "/carrello" || req.route.path == "/logout")
                return res.redirect("/login");
            req.userId = null;
            next();
        }   
        else
        {   
            jwt.verify(token, process.env.ACCESS_SECRET_JWT, (err,user) =>{
                if(err)
                    return res.redirect("/login");  
                req.userId = user.userId;
                req.token = token;
                next();
            });
        }
    },
};