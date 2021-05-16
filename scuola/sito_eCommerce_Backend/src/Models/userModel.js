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
            
            const query = "SELECT user_id FROM users WHERE email = '"+email+"' && pwd = '"+pwd+"';";//TODO: sanificazione input

            con.query(query, (err,res) =>{

                if(res.length)
                    solved(res[0].user_id);
                else
                    solved(false);

            });

        });  
    },
    signup: (name,email,pwd) =>{
        return new Promise(solved =>{
            
            const query = "INSERT INTO users VALUES (null,'"+name+"','"+email+"','"+pwd+"');";

            con.query(query, (err,res) =>{

                if(!err)
                    solved(true);
                else
                    solved(false);

            });

        });  
    },
    getLastId: (email,pwd) =>{
        return new Promise(solved =>{
            
            const query = "SELECT * FROM users;";

            con.query(query, (err,res) =>{

                if(!err)
                    solved(res[res.length-1].user_id);
                else
                    console.log("nessun utente");

            });

        });  
    },

    
}