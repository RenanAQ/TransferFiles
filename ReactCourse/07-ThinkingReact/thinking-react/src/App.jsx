import React, { useState } from 'react';
import InputControl from './components/InputControl';
import DisplayList from './components/DisplayList';

const App = () => {
  const [selectedCategory, setSelectedCategory] = useState('All');

  const handleCategoryChange = (category) => {
    setSelectedCategory(category);
   };
  //  console.log('setSelectedCategory', selectedCategory);
  return (
    <div>
      <InputControl onCategoryChange={handleCategoryChange} />
      <DisplayList category={selectedCategory} />
    </div>
  );
};

export default App;