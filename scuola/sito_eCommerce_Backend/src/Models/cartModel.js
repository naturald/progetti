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
    addToCart: (artId,userId) =>{
        return new Promise( solved =>{

            const query = "SELECT quant FROM cart WHERE fk_user_id = "+userId+" && fk_article_id = "+artId+";";

            con.query(query, (err,res) =>{
                if(res != undefined && res.length)
                {
                    if(res[0].quant > 9)
                        solved(false);
                    else
                    {
                        const quant = res[0].quant;
                        const query = "update cart set quant = "+(quant+1)+" where fk_user_id = "+userId+" && fk_article_id = "+artId+";";
                        con.query(query,(err,res) =>{

                            if(!err)
                                solved(true);
                            else
                                solved(false);

                        });
                    }

                }
                else
                {
                    const query = "INSERT INTO cart (fk_user_id,fk_article_id) VALUES ("+userId+","+artId+");";

                    con.query(query, (err,res) =>{

                        if(!err)
                            solved(true);
                        else
                            solved(false);

                    });           
                }
            });
        });
    },
    getQuant: (artId,userId) =>{
        return new Promise( solved =>{

            const query = "SELECT quant FROM cart WHERE fk_user_id = "+userId+" && fk_article_id = "+artId+";";

            con.query(query, (err,res) =>{

                if(!err && (res != undefined && res.length))
                    solved(res[0].quant);
                else
                    solved(false);

            });
        });
    },
    getAllEle: (userId) =>{
        return new Promise( solved =>{

            const query = "SELECT article_id,img,nome,price,quant FROM cart inner Join articles on fk_article_id = article_id Where fk_user_id = "+userId+";";

            con.query(query, (err,res) =>{

                if(!err && (res != undefined && res.length))
                    solved(res);
                else
                    solved(false);

            });
        });
    },
    decToCart: (artId,userId) =>{
        return new Promise( solved =>{

            const query = "SELECT quant FROM cart WHERE fk_user_id = "+userId+" && fk_article_id = "+artId+";";

            con.query(query, (err,res) =>{
                if(res != undefined && res.length)
                {
                    if(res[0].quant < 2)
                        solved(false);
                    else
                    {
                        const quant = res[0].quant;
                        const query = "update cart set quant = "+(quant-1)+" where fk_user_id = "+userId+" && fk_article_id = "+artId+";";
                        con.query(query,(err,res) =>{

                            if(!err)
                                solved(true);
                            else
                                solved(false);

                        });
                    }

                }
            });
        });
    },
    delCart: () =>{
        
        const query = "TRUNCATE cart;";

        con.query(query);
        
    },
    delEle: (artId,userId) =>{
        
        const query = "delete from cart where fk_user_id = "+userId+" && fk_article_id = "+artId+";";

        con.query(query);
        
    },
};