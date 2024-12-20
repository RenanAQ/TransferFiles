const express = require("express");
const path = require('path');

const rootDir = require('../utils/path');
const adminData = require('./admin');
const { title } = require("process");

const router = express.Router();

router.get("/", (req, res, next) => {
    const products = adminData.products;
    res.render('shop',{m_prods: products, m_docTitle: 'Renan Shop', path:'/', m_pageTitle: 'Renan Store'});
});

module.exports = router;