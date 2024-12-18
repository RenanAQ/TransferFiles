const express = require("express");
const bodyParser = require("body-parser");
const m_adminRoutes = require("./routes/admin");
const m_shopRoutes = require("./routes/shop")
const path = require('path')

const app = express();

app.use(bodyParser.urlencoded({ extended: false })); //parsing body
app.use(express.static(path.join(__dirname, 'public')))

app.use('/admin', m_adminRoutes);
app.use(m_shopRoutes);

//error handler
app.use((req, res, next)=>{
    res.status(404).sendFile(path.join(__dirname, 'views', '404.html'));
})


app.listen(3000);