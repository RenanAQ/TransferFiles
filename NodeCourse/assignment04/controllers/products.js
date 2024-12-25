const products = [];

exports.getAddProduct = (req, res, next) => {
  res.render("add-product", {
    m_pageTitle: "Add Product",
    path: "admin/add-product",
    formsCSS: true,
    productCSS: true,
    activeAddProduct: true,
  });
};

exports.postAddProduct = (req, res, next) => {
  products.push({ title: req.body.title });
  res.redirect("/");
};

exports.getProducts = (req, res, next) => {
  res.render("shop", {
    m_prods: products,
    m_docTitle: "Renan Shop",
    path: "/",
    m_pageTitle: "Renan Store",
    hasProducts: products.length > 0,
    activeShop: true,
    productCSS: true,
    layout: false,
  });
};