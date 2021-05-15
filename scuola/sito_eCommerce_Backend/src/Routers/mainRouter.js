const Controller = require('./../Controllers/mainController');

module.exports = app =>{

    app.get('/',Controller.root);
    app.get('/about',Controller.about);
    app.get('/carrello',Controller.carrello);
    app.get('/contattaci',Controller.contattaci);
    app.get('/notizie',Controller.notizie);
    app.get('/login',Controller.loginGet);
    app.post('/login',Controller.loginPost);
    app.get('/logout',Controller.logout);
}