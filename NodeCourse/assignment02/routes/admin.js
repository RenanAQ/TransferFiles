const express = require("express");

const router = express.Router();

// /admin/add-product => GET
router.get("/add-product", (req, res, next) => {
  console.log("In the middleware 1");
  res.send(
    '<form action="/admin/add-product" method="POST"><input type="text" name="m_title"><button type="submit">Add m_Product</button></form>'
  );
  // next(); //this allows the request to continue to the next middleware if we do not have a response
});
// /admin/add-product => POST
router.post("/add-product", (req, res, next) => {
  console.log(req.body);
  res.redirect("/");
});

module.exports = router;
