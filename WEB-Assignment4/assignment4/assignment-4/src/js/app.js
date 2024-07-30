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

var contentDiv = document.getElementById('main-content');

//h1
var header1 = document.createElement('h1');
header1.textContent = 'This is the first header';
//append h1
contentDiv.appendChild(header1);

function createProductCard(product) {
  // Create a <div> to hold the card
  const card = document.createElement('div');
  // Add the .card class to the <div>
  card.classList.add('card');

  // Create a product image, use the .card-image class
  const productImage = document.createElement('img'); //creating the tag
  productImage.src = product.imageUrl; //image source
  productImage.classList.add('card-image'); //creating a class
  card.appendChild(productImage); //appending
  
  var header3 = document.createElement('h3');
  header3.textContent = 'Product'
  card.appendChild(header3);

  // Return the card’s <div> element to the caller
  return card;
}
for (let index = 0; index < products.length; index++) {
  var prod1 = createProductCard(products[index]);
  contentDiv.appendChild(prod1);
  
}
