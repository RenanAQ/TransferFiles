/**
 * products.js
 *
 * The store's products are defined as an Array of product Objects.
 * Each product Object includes the following properties:
 *
 *  - id: String, a unique product identifier (e.g., "P1", "P2")
 *  - title: String, a short name for the product (e.g., "Gingerbread Cookie")
 *  - description: String, a description of the product
 *  - price: Number, the unit price of the item in whole cents (e.g., 100 = $1.00, 5379 = $53.79)
 *  - discontinued: Boolean, whether or not the product has been discontinued
 *  - categories: Array, the category id or ids to which this product belongs (e.g., ["c1"] or ["c1", "c2"])
 */

window.products = [
  /*
    {
      id: "P1",
      title: "Title 1",
      description: "Description 1...",
      price: 199,
      discontinued: false,
      categories: ["c1"]
    },
  */
  {
    id: "Cat01-P1",
    title: "Babolat",
    description: "Babolat Adult Racquet",
    price: 27999,
    discontinued: false,
    categories: ["Cat01"]
  },
  {
    id: "Cat01-P2",
    title: "Dunlop",
    description: "Dunlop Adult Racquet",
    price: 30999,
    discontinued: false,
    categories: ["Cat01"]
  },
  {
    id: "Cat01-P3",
    title: "Head",
    description: "Head Adult Racquet",
    price: 26999,
    discontinued: false,
    categories: ["Cat01"]
  },
  {
    id: "Cat01-P4",
    title: "Tecnifibre",
    description: "Tecnifibre Adult Racquet",
    price: 22999,
    discontinued: false,
    categories: ["Cat01"]
  },
  {
    id: "Cat01-P5",
    title: "Wilson",
    description: "Wilson Adult Racquet",
    price: 25999,
    discontinued: false,
    categories: ["Cat01"]
  },
  {
    id: "Cat01-P6",
    title: "Yonex",
    description: "Yonex Adult Racquet",
    price: 28999,
    discontinued: false,
    categories: ["Cat01"]
  },

  {
    id: "Cat02-P1",
    title: "Babolat",
    description: "Babolat Tennis Balls",
    price: 799,
    discontinued: false,
    categories: ["Cat02"]
  },
  {
    id: "Cat02-P2",
    title: "Penn",
    description: "Penn Tennis Balls",
    price: 699,
    discontinued: false,
    categories: ["Cat02"]
  },
  {
    id: "Cat02-P3",
    title: "Dunlop",
    description: "Dunlop Tennis Balls",
    price: 599,
    discontinued: false,
    categories: ["Cat02"]
  },
  {
    id: "Cat02-P4",
    title: "Wilson",
    description: "Wilson Tennis Balls",
    price: 499,
    discontinued: false,
    categories: ["Cat02"]
  },
  {
    id: "Cat02-P5",
    title: "ATR Sports",
    description: "ATR Sports Tennis Balls",
    price: 899,
    discontinued: true,
    categories: ["Cat02"]
  },

  {
    id: "Cat03-P1",
    title: "Asics",
    description: "Asics Tennis Shoes",
    price: 18099,
    discontinued: false,
    categories: ["Cat03"]
  },
  {
    id: "Cat03-P2",
    title: "ATR Sports",
    description: "ATR Tennis Shoes",
    price: 9899,
    discontinued: true,
    categories: ["Cat03"]
  },
  {
    id: "Cat03-P3",
    title: "New Balance",
    description: "New Balance Tennis Shoes",
    price: 20999,
    discontinued: false,
    categories: ["Cat03"]
  },
  {
    id: "Cat03-P4",
    title: "Nike",
    description: "Nike Tennis Shoes",
    price: 29999,
    discontinued: false,
    categories: ["Cat03"]
  },
  {
    id: "Cat03-P5",
    title: "Head",
    description: "Head Tennis Shoes",
    price: 19999,
    discontinued: false,
    categories: ["Cat03"]
  },
  {
    id: "Cat03-P6",
    title: "Yonex",
    description: "Yonex Tennis Shoes",
    price: 17999,
    discontinued: false,
    categories: ["Cat03"]
  },

  {
    id: "Cat04-P6",
    title: "Babolat",
    description: "Babolat Tennis Bag",
    price: 17999,
    discontinued: false,
    categories: ["Cat04"]
  },
  {
    id: "Cat04-P6",
    title: "Head",
    description: "Head Tennis Bag",
    price: 15999,
    discontinued: false,
    categories: ["Cat04"]
  },
  {
    id: "Cat04-P6",
    title: "Dunlop",
    description: "Dunlop Tennis Bag",
    price: 16999,
    discontinued: false,
    categories: ["Cat04"]
  },
  {
    id: "Cat04-P6",
    title: "Wilson",
    description: "Wilson Tennis Bag",
    price: 19999,
    discontinued: false,
    categories: ["Cat04"]
  },
  {
    id: "Cat04-P6",
    title: "ATR Sports",
    description: "ATR Sports Tennis Bag",
    price: 10999,
    discontinued: true,
    categories: ["Cat04"]
  },
  {
    id: "Cat04-P6",
    title: "Tecnifibre",
    description: "Tecnifibre Tennis Bag",
    price: 11999,
    discontinued: false,
    categories: ["Cat04"]
  },

  {
    id: "Cat05-P6",
    title: "Tecnifibre",
    description: "Tecnifibre Tennis String",
    price: 1999,
    discontinued: false,
    categories: ["Cat05"]
  },
  {
    id: "Cat05-P6",
    title: "Luxilon",
    description: "Luxilon Tennis String",
    price: 3999,
    discontinued: false,
    categories: ["Cat05"]
  },
  {
    id: "Cat05-P6",
    title: "Solinco",
    description: "Solinco Tennis String",
    price: 999,
    discontinued: false,
    categories: ["Cat05"]
  },
  {
    id: "Cat05-P6",
    title: "Wilson",
    description: "Wilson Tennis String",
    price: 2999,
    discontinued: false,
    categories: ["Cat05"]
  }
];
