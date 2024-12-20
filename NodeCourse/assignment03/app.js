const express = require("express");
const bodyParser = require("body-parser");
const path = require('path')
const app = express();


app.set('view engine', 'ejs');
app.set('views', 'views');

const m_adminRoutes = require("./routes/admin");
const m_shopRoutes = require("./routes/shop")

app.use(bodyParser.urlencoded({ extended: false })); //parsing body
app.use(express.static(path.join(__dirname, 'public')))

app.use('/admin', m_adminRoutes.routes);
app.use(m_shopRoutes);

//error handler
app.use((req, res, next)=>{
    res.status(404).render('404', { m_pageTitle: 'Page not Found'})
})


app.listen(3000);