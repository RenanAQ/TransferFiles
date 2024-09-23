import React from 'react';

const InputControl = ({ onCategoryChange }) => {
  const handleChange = (e) => {
    onCategoryChange(e.target.value); // Pass the selected value to the parent component
  };

  return (
    <div>
      <input type="text" placeholder="Search..." id='input-search'></input>
      <input type='checkbox' onChange={handleChange}></input>
      <label>
        Only show products in stock
        {/* <select onChange={handleChange}>
        <option value="All">All</option>
          <option value="Fruits">Fruits</option>
          <option value="Vegetables">Vegetables</option>
        </select> */}
      </label>
    </div>
  );
};

export default InputControl;