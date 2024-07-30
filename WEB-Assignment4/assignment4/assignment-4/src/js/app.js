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

// Function to create product card
function createProductCard(product) {
  // Create a <div> to hold the card
  const card = document.createElement('div');
  // Add the .card class to the <div>
  card.classList.add('card');

  // Create a product image, use the .card-image class
  const productImage = document.createElement('img');
  productImage.src = product.imageUrl;
  productImage.alt = product.title;  // Add alt attribute for better accessibility
  productImage.classList.add('card-image');
  card.appendChild(productImage);

  // Create a <div> for card content, use the .card-content class
  const cardContent = document.createElement('div');
  cardContent.classList.add('card-content');

  // Create and append product name
  const productName = document.createElement('h2');
  productName.classList.add('card-title');
  productName.textContent = product.title;
  cardContent.appendChild(productName);

  // Create and append product description
  const productDescription = document.createElement('p');
  productDescription.classList.add('card-description');
  productDescription.textContent = product.description;
  cardContent.appendChild(productDescription);

  // Create and append product price
  const productPrice = document.createElement('p');
  productPrice.classList.add('card-price');
  productPrice.textContent = `$${(product.price / 100).toFixed(2)}`;
  cardContent.appendChild(productPrice);

  // Append card content to the card
  card.appendChild(cardContent);

  // Return the card’s <div> element to the caller
  return card;
}

document.addEventListener('DOMContentLoaded', function() {
  const productContainer = document.getElementById('product-container');

  function displayProducts(productsToDisplay) {
    // Clear existing content
    productContainer.innerHTML = '';
    // Append new product cards
    productsToDisplay.forEach(product => {
      const productCard = createProductCard(product);
      productContainer.appendChild(productCard);
    });
  }

  // Initial load - display all products
  displayProducts(products);

  // Category buttons event listeners
  const categoryButtons = document.querySelectorAll('.category-button');
  categoryButtons.forEach(button => {
    button.addEventListener('click', function() {
      const category = this.getAttribute('data-category');
      const filteredProducts = products.filter(product => product.categories.includes(category));
      displayProducts(filteredProducts);
    });
  });
});