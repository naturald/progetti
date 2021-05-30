const Mysql = require("mysql");

const con = Mysql.createConnection({
    host: "localhost",
    user: "web_visitor",
    password: "",
    database: "e_commerce"
});

con.connect(err =>{
    if(err)
        console.log("problema di connesione");
});

module.exports = {
    getArticleFromCart: (artId,cartId) =>{
        return new Promise( solved =>{

            const query = "select article_id,img,articles.name,price,quant from cart_records inner join articles on fk_article_id = article_id where fk_cart_id = "+cartId+" && fk_article_id = "+artId+";";

            con.query(query, (err,res) =>{

                if(!err && (res != undefined && res.length))
                    solved(res[0]);
                else
                    solved(false);

            });
        });
    },
    getAllArticlesFromCart: (cartId) =>{
        return new Promise( solved =>{

            const query = "select article_id,img,articles.name,price,quant from cart_records inner join articles on fk_article_id = article_id where fk_cart_id = "+cartId+";";

            con.query(query, (err,res) =>{

                if(!err && (res != undefined && res.length))
                    solved(res);
                else
                    solved(false);

            });
        });
    },
    addToCart: (artId,cartId) =>{
        return new Promise( solved =>{

            const query = " select * from cart_records where fk_article_id = "+artId+" && fk_cart_id = "+cartId+";";
            con.query(query, (err,res) =>{
                if(res != undefined && res.length)
                {
                    const result = res;
                    if(res[0].quant > 9)
                        solved({quant: 10});
                    else
                    {
                        const quant = res[0].quant;
                        const query = "update cart_records set quant = "+(quant+1)+" where record_id = "+res[0].record_id+";";
                        con.query(query,(err,res) =>{

                            if(!err)
                            {
                                result[0].quant += 1;
                                solved(result[0]);
                            }
                            else
                                solved(false);

                        });
                    }

                }
                else
                {
                    const query = "INSERT INTO cart_records (fk_article_id,fk_cart_id) VALUES ("+artId+","+cartId+");";

                    con.query(query, (err,res) =>{

                        if(!err)
                        {
                            const query = "SELECT * FROM cart_records WHERE fk_article_id = "+artId+" && fk_cart_id = "+cartId+";";
                            con.query(query, (err,res) =>{
                                solved(res[0]);
                            });
                        }
                        else
                            solved(false);

                    });           
                }
            });
        });
    },
    getQuant: (artId,cartId) =>{
        return new Promise( solved =>{

            const query = "SELECT quant FROM cart_records WHERE fk_cart_id = "+cartId+" && fk_article_id = "+artId+";";

            con.query(query, (err,res) =>{

                if(!err && (res != undefined && res.length))
                    solved(res[0].quant);
                else
                    solved(false);

            });
        });
    },
    decToCart: (artId,cartId) =>{
        return new Promise( solved =>{

            const query = "select * from cart_records where fk_article_id = "+artId+" && fk_cart_id = "+cartId+";";

            con.query(query, (err,res) =>{
                if(res != undefined && res.length)
                {
                    const result = res;
                    if(res[0].quant < 2)
                        solved({quant: 1});
                    else
                    {
                        const quant = res[0].quant;
                        const query = "update cart_records set quant = "+(quant-1)+" where record_id = "+res[0].record_id+";";
                        con.query(query,(err,res) =>{
                            result[0].quant --;
                            if(!err)
                                solved(result[0]);
                            else
                                solved(false);

                        });
                    }

                }
            });
        });
    },
    delCart: (userId) =>{
        
        const query = "delete from cart_records where fk_cart_id = (select max(cart_id) from carts where fk_user_id = "+userId+");";

        con.query(query);
        
    },
    delEle: (artId,cartId) =>{
        return new Promise( solved => {
            const query = "delete from cart_records where fk_article_id = "+artId+" &&  fk_cart_id = "+cartId+";";
            
            con.query(query,(err,res) =>{
                if(res.changedRows != 0)
                    solved(true);
                else
                    solved(false);
            });
        });
    },
    getLastCartId: (userId) =>{
        
        return new Promise( solved =>{
            const query = "select max(cart_id) from carts where fk_user_id = "+userId+";";

            con.query(query,(err,res) =>{
                if(!err && res != undefined && res.length)
                    solved(res[0]['max(cart_id)']);
                else
                    solved(false);
            });
        });
    },
    getAllCartsId: (userId) =>{
        
        return new Promise( solved =>{
            const query = "select cart_id from carts where fk_user_id = "+userId+";";

            con.query(query,(err,res) =>{
                if(!err && res != undefined && res.length)
                    solved(res);
                else
                    solved(false);
            });
        });
    },
};