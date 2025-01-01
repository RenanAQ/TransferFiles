//header for express
const express = require("express");
const app = express();
const port = 3000;

//header for ejs
// const ejs = require("ejs");
app.set("view engine", "ejs");

//middleware form
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.render("body", { m_pageTitle: "Area Calc"});
});

app.post("/submit", (req, res)=>{
  res.send(req.body)
});

//resource folder
app.use(express.static("public"));

app.listen(port, () => {
  console.log(`Listening @ ${port}`);
});
