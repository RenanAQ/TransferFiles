const express = require("express");
const bodyParser = require("body-parser");
const m_adminRoutes = require("./routes/admin");
const m_shopRoutes = require("./routes/shop")

const app = express();

app.use(bodyParser.urlencoded({ extended: false })); //parsing body

app.use('/admin', m_adminRoutes);
app.use(m_shopRoutes);

//error handler
app.use((req, res, next)=>{
    res.status(404).send('<h1>Page not found!</h1>')
})


app.listen(3000);