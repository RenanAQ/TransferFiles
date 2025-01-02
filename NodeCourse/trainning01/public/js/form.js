function showShapeFields(shape) {
    const container = document.getElementById('fieldsContainer');
    container.innerHTML = ''; // clear previous fields

    if (shape === 'Square') {
      container.innerHTML = `
        <div class="field-container">
          <label>Side:</label>
          <input type="number" step="0.01" name="side" required />
        </div>
      `;
    } else if (shape === 'Rectangle') {
      container.innerHTML = `
        <div class="field-container">
          <label>Length:</label>
          <input type="number" step="0.01" name="length" required />
        </div>
        <div class="field-container">
          <label>Width:</label>
          <input type="number" step="0.01" name="width" required />
        </div>
      `;
    } else if (shape === 'Triangle') {
      container.innerHTML = `
        <div class="field-container">
          <label>Base:</label>
          <input type="number" step="0.01" name="base" required />
        </div>
        <div class="field-container">
          <label>Height:</label>
          <input type="number" step="0.01" name="height" required />
        </div>
      `;
    } else if (shape === 'Circle') {
      container.innerHTML = `
        <div class="field-container">
          <label>Radius:</label>
          <input type="number" step="0.01" name="radius" required />
        </div>
      `;
    } else if (shape === 'Parallelogram') {
      container.innerHTML = `
        <div class="field-container">
          <label>Base:</label>
          <input type="number" step="0.01" name="base" required />
        </div>
        <div class="field-container">
          <label>Height:</label>
          <input type="number" step="0.01" name="height" required />
        </div>
      `;
    } else if (shape === 'Trapezoid') {
      container.innerHTML = `
        <div class="field-container">
          <label>Base 1:</label>
          <input type="number" step="0.01" name="base1" required />
        </div>
        <div class="field-container">
          <label>Base 2:</label>
          <input type="number" step="0.01" name="base2" required />
        </div>
        <div class="field-container">
          <label>Height:</label>
          <input type="number" step="0.01" name="height" required />
        </div>
      `;
    } else {
      // If "--Choose an option--" is selected or anything else, do nothing
      container.innerHTML = '';
    }
  }