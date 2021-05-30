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

                if(!err && res!=undefined && res.length)
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
                {
                    const query = "SELECT max(user_id) FROM users";
                    con.query(query, (err,res) =>{
                        const query = "insert into carts values (null,"+res[0]['max(user_id)']+");";
                        con.query(query);
                        solved(res[0]['max(user_id)']);
                    });
                    
                }
                else
                    solved(false);

            });

        });  
    },
    getLastId: (email,pwd) =>{
        return new Promise(solved =>{
            
            const query = "SELECT max(user_id) FROM users;";

            con.query(query, (err,res) =>{
                if(!err)
                    solved(res[0]['max(user_id)']);
                else
                    console.log("nessun utente");

            });

        });  
    },

    
}