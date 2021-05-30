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
    getAllArt: () =>
    {
        return new Promise(resolved =>{
            const query = "SELECT * FROM articles;";

            con.query(query,(err,res) =>{
                
                if(!err)
                    resolved(res);
                else    
                    resolved(-1);
            });
        });
    },
    getArtById: (artId) =>
    {
        return new Promise(resolved =>{
            const query = "SELECT * FROM articles WHERE article_id = "+artId+";";

            con.query(query,(err,res) =>{
                
                if(!err)
                    resolved(res);
                else    
                    resolved(-1);
            });
        });
    }
};