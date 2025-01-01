document.addEventListener('DOMContentLoaded', () => {
    const shapeSelect = document.getElementById('shape');
    const selectedShapeDiv = document.getElementById('selectedShape');
  
    shapeSelect.addEventListener('change', () => {
      const chosenShape = shapeSelect.value;
  
      if (!chosenShape) {
        selectedShapeDiv.textContent = '';
        return;
      }
  
      selectedShapeDiv.textContent = `You selected: ${chosenShape}`;
    });
  });