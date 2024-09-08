import React from "react";
import { MARKET } from "../util/data";

const DisplayList = ({ category }) => {
  const filteredItems =
    category === "All"
      ? MARKET
      : MARKET.filter((item) => item.category === category);

  return (
    <table>
      <thead>
        <tr>
          <th>Name</th>
          <th>Price</th>
        </tr>
      </thead>
      <tbody>
        {filteredItems.map((item, index) => (
          <tr key={index}>
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
