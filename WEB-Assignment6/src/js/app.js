/**
 * WEB222 – Assignment 05
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Renan de Alencar Queiroz
 *      Student ID: 129280236
 *      Date:       Jul 29, 2024
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { products, categories } = window;

// For debugging, display all of our data in the console
console.log({ products, categories }, "Store Data");

//var mainContentDiv = document.getElementById("main-content"); //main div

document.addEventListener("DOMContentLoaded", () => {
  initializeCategories();
  displayFirstProduct(products); // Display first product by default
});

function initializeCategories() {
  const menu = document.querySelector("#menu");
  categories.forEach((category) => {
    const button = document.createElement("button");
    button.textContent = category.name;
    button.addEventListener("click", () => {
      const filteredProducts = products.filter((product) =>
        product.categories.includes(category.id)
      );
      displayProducts(filteredProducts);
    });
    menu.appendChild(button);
  });
}

function createProductCard(product) {
  // Create a <div> to hold the card
  const card = document.createElement("article");
  // Add the .card class to the <div>
  card.classList.add("card");

  // Create a product image, use the .card-image class
  const productImage = document.createElement("img"); //creating the tag
  productImage.src = product.imageUrl; //image source
  productImage.classList.add("card-image"); //creating a class
  card.appendChild(productImage); //appending

  // Text about the products
  var header3 = document.createElement("h3"); //title
  header3.textContent = product.title;
  card.appendChild(header3);
  var productDesc = document.createElement("p"); //description
  productDesc.textContent = product.description;
  card.appendChild(productDesc);
  var productPrice = document.createElement("footer"); //price
  productPrice.textContent = "$" + product.price / 100;
  card.appendChild(productPrice);

  // Return the card’s <div> element to the caller
  return card;
}

function displayProducts(products) {
  const mainContentDiv = document.getElementById("main-content");
  mainContentDiv.innerHTML = "";
  products.forEach((product) => {
    const prod = createProductCard(product);
    mainContentDiv.appendChild(prod);
  });
}

function displayFirstProduct(products) {
  const mainContentDiv = document.getElementById("main-content");
  mainContentDiv.innerHTML = "";
  if (products.length > 0) {
    const firstProduct = createProductCard(products[0]);
    mainContentDiv.appendChild(firstProduct);
  }
}

// JavaScript to handle the form submission
document.getElementById("myForm").addEventListener("submit", function (event) {
  event.preventDefault(); // Prevent the default form submission

  const formData = new FormData(this); // Get form data

  // Convert FormData to a plain object
  const data = {};
  formData.forEach((value, key) => {
    data[key] = value;
  });

  // Send the POST request using Fetch API
  fetch("https://httpbin.org/post", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(data),
  })
    .then((response) => response.json())
    .then((result) => {
      console.log("Success:", result); // Log the result to the console
    })
    .catch((error) => {
      console.error("Error:", error); // Log any errors to the console
    });
});
