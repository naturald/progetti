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
    login: (email,pwd) =>{
        return new Promise(solved =>{
            
            const query = "SELECT nome FROM users WHERE email = '"+email+"' && pwd = '"+pwd+"';";//TODO: sanificazione input

            con.query(query, (err,res) =>{

                if(res.length)
                    solved(true);
                else
                    solved(false);

            });

        });  
    },

    
}