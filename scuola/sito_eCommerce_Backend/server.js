require('dotenv').config();
const Express = require("express");
const Session = require('express-session');
const Router = require('./src/Routers/router');
const BodyParser = require('body-parser');

const app = Express();

app.use(BodyParser.urlencoded({extended:false}));
app.use(Express.json());
app.set("view engine", "ejs");
app.set("views", __dirname + "/src/Views");
app.use("/assets",Express.static(__dirname + "/src/assets"));
app.use(Session({
    secret:"shhh",
    resave: true,
    saveUninitialized: true
}));

Router(app);

app.listen(3000,() => { console.log("Attivo su porta 3000"); });