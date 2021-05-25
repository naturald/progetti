const Controller = require('../Controllers/mainController');
const APIController = require('../Controllers/apiController');

module.exports = app =>{

    app.get('/',Controller.root);
    app.get('/about',Controller.about);
    app.get('/contattaci',Controller.contattaci);
    app.get('/notizie',Controller.notizie);
    app.get('/carrello',Controller.carrello);
    app.get('/articolo',Controller.articolo);
    app.get('/articoli',Controller.articoli);

    //auth
    app.get('/login',Controller.loginGet);
    app.post('/login',Controller.loginPost);
    app.post('/signup',Controller.signup);
    app.get('/logout',Controller.logout);

    //API
    app.get('/api/articles',APIController.getAllArticoli);
    app.get('/api/articles/:artId',APIController.getArticolo);
    //TODO: mettere endpoints per uttti elementi carrello e un solo elemento
    app.post('/api/carts/:cartId/articles',APIController.addToCart);
    app.put('/api/carts/:cartId/articles/:artId',APIController.decToCart);
    app.delete('/api/carts/:cartId',APIController.delCart);
    app.get('/api/carts/:cartId/articles/:artId',APIController.delEleCart);

}
