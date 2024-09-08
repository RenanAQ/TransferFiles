import React, { useState } from 'react';
import InputControl from './components/InputControl';
import DisplayList from './components/DisplayList';

const App = () => {
  const [selectedCategory, setSelectedCategory] = useState('All');

  const handleCategoryChange = (category) => {
    setSelectedCategory(category);
   };
  return (
    <div>
      <InputControl onCategoryChange={handleCategoryChange} />
      <p>Selected Category: {selectedCategory}</p>
      <DisplayList category={selectedCategory} />
    </div>
  );
};

export default App;