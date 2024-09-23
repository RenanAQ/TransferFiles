import React from "react";
import { MARKET } from "../util/data";

const DisplayList = ({ category }) => {
  const fruits = MARKET.filter((item) => item.category === "Fruits");
  const vegetables = MARKET.filter((item) => item.category === "Vegetables");

  return (
    <table>
      <thead id="table-head">
        <tr>
          <th>Name</th>
          <th>Price</th>
        </tr>
      </thead>
      <tbody>
        <tr id="fruits-category">
          <th>Fruits</th>
        </tr>
        {fruits.map((item, index) => (
          <tr key={index} id="fruit-display">
            <td>{item.name}</td>
            <td>{item.price}</td>
            <td>{item.stocked ? "In Stock" : "Out of Stock"}</td>
          </tr>
        ))}
        <tr id="vegetables-category">
          <th>Vegetables</th>
        </tr>
        {vegetables.map((item, index) => (
          <tr key={index} id="vegetable-display">
            <td>{item.name}</td>
            <td>{item.price}</td>
            <td>{item.stocked ? "In Stock" : "Out of Stock"}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
};

export default DisplayList;
