const Controller = require('../Controllers/mainController');

module.exports = app =>{

    app.get('/',Controller.root);
    app.get('/about',Controller.about);
    app.get('/carrello',Controller.carrello);
    app.get('/contattaci',Controller.contattaci);
    app.get('/notizie',Controller.notizie);
    app.get('/login',Controller.loginGet);
    app.post('/login',Controller.loginPost);
    app.post('/signup',Controller.signup);
    app.get('/logout',Controller.logout);
    app.get('/articoli',Controller.articoli);
    app.get('/articolo/:artId',Controller.articolo);
    app.get('/carrello',Controller.carrello);
    app.get('/addToCart/:artId',Controller.addToCart);
    app.get('/decToCart/:artId',Controller.decToCart);
    app.get('/delCart',Controller.delCart);
    app.get('/delEleCart/:artId',Controller.delEleCart);

}
