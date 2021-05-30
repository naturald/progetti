const UserModel = require("../Models/UserModel");
const ArtModel = require("../Models/artModel");
const CartModel = require("../Models/cartModel");
const jwt = require('jsonwebtoken');

module.exports = {
    login: async (req,res) =>{
        try
        {
            const result = await UserModel.login(req.body.email,req.body.pwd);
            if(result)
            {
                const user = {userId: result};
                const accessToken = jwt.sign(user,process.env.ACCESS_SECRET_JWT);
                res.setHeader('Set-Cookie', 'token='+accessToken+'; HttpOnly; Path=/');
                res.json(accessToken);   
            }
            else
            {
                res.sendStatus(403).send();
            }
        }
        catch
        {
            res.sendStatus(500).send();
        }
    },
    signup: async (req,res) =>{
        try
        {
            const result = await UserModel.signup(req.body.name,req.body.email,req.body.pwd);
            if(result)
            {
                const user = {userId: result};
                const accessToken = jwt.sign(user,process.env.ACCESS_SECRET_JWT);
                res.setHeader('Set-Cookie', 'token='+accessToken+'; HttpOnly; Path=/');
                res.json(accessToken);   
            }
            else
            {
                res.sendStatus(400);
            }
        }
        catch
        {
            res.sendStatus(500);
        }
       

    },
    getAllArticoli: async (req,res)=>{
        const articles = await ArtModel.getAllArt();
        
        if(articles != -1)
            res.json(articles);
    },
    getArticolo: async (req,res)=>{
        
        try
        {
            const article = await ArtModel.getArtById(req.params.artId);

            if(article != -1)
            {
                res.json(article[0]);
            }
            else
                res.sendStatus(400);
        }
        catch
        {
            res.sendStatus(500);
        }
    
    },
    addToCart: async(req,res)=>{

        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                const cartRecord = await CartModel.addToCart(req.body.artId,req.params.cartId);
                if(cartRecord)
                    res.json(cartRecord);
                else
                    res.send("massima quantita raggiunta");
            }   
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
        
    },
    decToCart: async (req,res)=>{
        
        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                const cartRecord = await CartModel.decToCart(req.params.artId,req.params.cartId);
                if(cartRecord)
                    res.json(cartRecord);
                else
                    res.send("minima quantita raggiunta");
            }   
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
        
        
    },
    delCart: async (req,res)=>{
        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                CartModel.delCart(req.params.cartId);
                res.sendStatus(200);
            }
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
       
    },
    delEleCart: async (req,res)=>{
        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                const respo = await CartModel.delEle(req.params.artId,req.params.cartId);
                
                res.sendStatus(200);
            }
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
        
    },
    getAllArticoliFromCart: async (req,res)=>{
        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                const cartRecord = await CartModel.getAllArticlesFromCart(req.params.cartId);
                
                if(cartRecord)
                    res.json(cartRecord);
                else
                    res.send([]);
            }
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
        
    },
    getArticoloFromCart: async (req,res)=>{
        try
        {
            const lastCart = await CartModel.getLastCartId(req.user.userId);

            if(lastCart == req.params.cartId)
            {
                
                const cartRecord = await CartModel.getArticleFromCart(req.params.artId,req.params.cartId);
                if(cartRecord)
                    res.json(cartRecord);
                else
                    res.send("articolo non trovato");
            }
            else
                res.sendStatus(403);
        }
        catch
        {
            res.sendStatus(500);
        }
        
    },
    getLastCart: async (req,res)=>{
        let cartId = null;
        if(req.params.userId == req.user.userId)
            cartId = await CartModel.getLastCartId(req.params.userId);
        else
            return res.sendStatus(403);
            
        if(cartId)
            res.json(cartId);
        else 
            res.send("No articles");
    },
    authToken: (req,res,next) =>{ //midleware
        const token =  req.query.auth;
        //const token = authHeader && authHeader.split(" ")[1]; // se authHeader ce allora fai quello dopo
        if(token == null)   
            return res.sendStatus(401);

        jwt.verify(token, process.env.ACCESS_SECRET_JWT, (err,user) =>{
            if(err)
                return res.sendStatus(403);  
            req.user = user;
            req.token = token;
            next();
        });
    },
}
