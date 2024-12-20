const express = require("express");
const adminData = require("./admin");
const router = express.Router();

router.get("/", (req, res, next) => {
  const products = adminData.products;
  res.render("shop", {
    m_prods: products,
    m_docTitle: "Renan Shop",
    path: "/",
    m_pageTitle: "Renan Store",
    hasProducts: products.length > 0,
    activeShop: true,
    productCSS: true,
    layout: false
  });
});

module.exports = router;
