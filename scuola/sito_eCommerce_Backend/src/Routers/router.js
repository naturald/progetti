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
    app.post('/api/auth/login',APIController.login);
    app.post('/api/auth/signup',APIController.signup);

    app.get('/api/articles',APIController.getAllArticoli);
    app.get('/api/articles/:artId',APIController.authToken,APIController.getArticolo);

    app.get('/api/carts/:cartId/articles',APIController.authToken,APIController.getAllArticoliFromCart);
    app.get('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.getArticoloFromCart);
    app.post('/api/carts/:cartId/articles',APIController.authToken,APIController.addToCart);
    app.put('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.decToCart);
    app.delete('/api/carts/:cartId/articles',APIController.authToken,APIController.delCart);
    app.delete('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.delEleCart);

}
