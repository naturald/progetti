const UserModel = require("../Models/UserModel");
const ArtModel = require("../Models/artModel");
const CartModel = require("../Models/cartModel");

module.exports = {
    getAllArticoli: async (req,res)=>{
        const articles = await ArtModel.getAllArt();
        
        if(articles != -1)
            res.json(articles);
    },
    getArticolo: async (req,res)=>{
        
        const article = await ArtModel.getArtById(req.params.artId);
        //const quant = await CartModel.getQuant(req.params.artId,req.params.userId);

        if(article != -1)
            res.json(article[0]);
    },
    addToCart: async(req,res)=>{

        const cartRecord = await CartModel.addToCart(req.body.artId,req.params.cartId);

        res.json(cartRecord);
    },
    decToCart: async (req,res)=>{

        const cartRecord = CartModel.decToCart(req.params.artId,req.params.cartId);

        res.json(cartRecord);
    },
    delCart: async (req,res)=>{

        CartModel.delCart(req.params.cartId);

        res.redirect("/");
    },
    delEleCart: async (req,res)=>{

        CartModel.delEle(req.params.artId,req.params.cartId);

        res.redirect("/");
    },
}
