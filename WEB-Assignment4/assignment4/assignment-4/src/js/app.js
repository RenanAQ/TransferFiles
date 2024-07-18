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

const categoryMenu = document.querySelector('#menu');
const categoryTitle = document.getElementById('category-title');
const categoryItems = document.getElementById('category-items');

// Create buttons for categories and display the first category by default
Object.keys(categories).forEach(category => {
  const button = document.createElement('button');
  button.textContent = category;
  button.addEventListener('click', () => displayCategory(category));
  categoryMenu.appendChild(button);
});
