const Controller = require('../Controllers/mainController');
const APIController = require('../Controllers/apiController');

module.exports = app =>{

    app.get('/',Controller.authToken,Controller.root);
    app.get('/about',Controller.authToken,Controller.about);
    app.get('/contattaci',Controller.authToken,Controller.contattaci);
    app.get('/notizie',Controller.authToken,Controller.notizie);
    app.get('/carrello',Controller.authToken,Controller.carrello);
    app.get('/articolo/:artId',Controller.authToken,Controller.articolo);
    app.get('/articoli',Controller.authToken,Controller.articoli);
    app.get('/gallery',Controller.authToken,Controller.gallery);

    //auth
    app.get('/login',Controller.loginGet);
    app.get('/logout',Controller.logout);

    //API
    app.post('/api/auth/login',APIController.login);
    app.post('/api/auth/signup',APIController.signup);

    app.get('/api/articles',APIController.getAllArticoli);
    app.get('/api/articles/:artId',APIController.getArticolo);

    app.get('/api/carts/last/users/:userId',APIController.authToken,APIController.getLastCart);
    app.get('/api/carts/:cartId/articles',APIController.authToken,APIController.getAllArticoliFromCart);
    app.get('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.getArticoloFromCart);
    app.post('/api/carts/:cartId/articles',APIController.authToken,APIController.addToCart);
    app.put('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.decToCart);
    app.delete('/api/carts/:cartId/articles',APIController.authToken,APIController.delCart);
    app.delete('/api/carts/:cartId/articles/:artId',APIController.authToken,APIController.delEleCart);

}
