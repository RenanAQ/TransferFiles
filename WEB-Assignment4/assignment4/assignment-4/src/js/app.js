/**
 * WEB222 – Assignment 04
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
 *      Date:       Jul 17, 2024
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { products, categories } = window;

// For debugging, display all of our data in the console
console.log({ products, categories }, "Store Data");


document.addEventListener('DOMContentLoaded', () => {
    initializeCategories();
    showProductsByCategory(categories[0].id); // Display the first category by default
  });
  
  function initializeCategories() {
    const menu = document.querySelector('#menu'); //Select the menu ID
    categories.forEach(category => {
      const button = document.createElement('button'); //Create the buttons
      button.textContent = category.name; //Name the buttons as the category
      button.addEventListener('click', () => showProductsByCategory(category.id));
      menu.appendChild(button);
    });
  }
  
  function showProductsByCategory(categoryId) {
    const category = categories.find(cat => cat.id === categoryId);
    const productList = document.querySelector('#category-products');
    const categoryTitle = document.querySelector('#selected-category');
  
    // Update the category title
    categoryTitle.textContent = category.name;
  
    // Clear the current product list
    productList.innerHTML = '';
  
    // Filter and display products
    const filteredProducts = products.filter(product => 
      product.categories.includes(categoryId) && !product.discontinued
    );
  
    filteredProducts.forEach(product => {
      const row = document.createElement('tr');
  
      // Click handler for the product
      row.addEventListener('click', () => console.log(product));
  
      const titleCell = document.createElement('td');
      titleCell.textContent = product.title;
  
      const descriptionCell = document.createElement('td');
      descriptionCell.textContent = product.description;
  
      const priceCell = document.createElement('td');
      priceCell.textContent = formatPrice(product.price);
  
      row.appendChild(titleCell);
      row.appendChild(descriptionCell);
      row.appendChild(priceCell);
  
      productList.appendChild(row);
    });
  }
  
  function formatPrice(cents) {
    return new Intl.NumberFormat('en-CA', { style: 'currency', currency: 'CAD' }).format(cents / 100);
  }
  