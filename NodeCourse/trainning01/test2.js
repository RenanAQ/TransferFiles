const express = require('express');
const app = express();

// Middleware to parse application/x-www-form-urlencoded (from HTML forms)
app.use(express.urlencoded({ extended: true }));

// Display the form (GET request)
app.get('/', (req, res) => {
  const htmlForm = `
    <!DOCTYPE html>
    <html>
    <head>
      <meta charset="UTF-8" />
      <title>Shape Form</title>
      <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        label { display: inline-block; width: 120px; margin-bottom: 5px; }
        .field-container { margin: 10px 0; }
      </style>
    </head>
    <body>
      <h1>Enter your info and select a shape</h1>
      <form action="/submit" method="POST">
        <div class="field-container">
          <label>Name:</label>
          <input type="text" name="name" required />
        </div>

        <div class="field-container">
          <label>Email:</label>
          <input type="email" name="email" required />
        </div>

        <div class="field-container">
          <label>Age:</label>
          <input type="number" step="0.01" name="m_age" required />
        </div>

        <div class="field-container">
          <label for="shape">Select the shape you want to calculate</label>
          <select name="shape" id="m_shape" onchange="showShapeFields(this.value)">
            <option value="">--Choose an option--</option>
            <option value="Square">Square</option>
            <option value="Triangle">Triangle</option>
            <option value="Rectangle">Rectangle</option>
            <option value="Circle">Circle</option>
            <option value="Parallelogram">Parallelogram</option>
            <option value="Trapezoid">Trapezoid</option>
          </select>
        </div>

        <!-- Container for dynamic shape fields -->
        <div id="shapeFields"></div>

        <button type="submit">Submit</button>
      </form>

      <script>
        function showShapeFields(shape) {
          const container = document.getElementById('shapeFields');
          container.innerHTML = ''; // clear previous fields

          if (shape === 'Square') {
            // For a square, we might need 1 side input
            container.innerHTML = \`
              <div class="field-container">
                <label>Side:</label>
                <input type="number" step="0.01" name="side" required />
              </div>
            \`;
          } else if (shape === 'Rectangle') {
            // For a rectangle, we need length & width
            container.innerHTML = \`
              <div class="field-container">
                <label>Length:</label>
                <input type="number" step="0.01" name="length" required />
              </div>
              <div class="field-container">
                <label>Width:</label>
                <input type="number" step="0.01" name="width" required />
              </div>
            \`;
          } else if (shape === 'Triangle') {
            // For a triangle, maybe base & height
            container.innerHTML = \`
              <div class="field-container">
                <label>Base:</label>
                <input type="number" step="0.01" name="base" required />
              </div>
              <div class="field-container">
                <label>Height:</label>
                <input type="number" step="0.01" name="height" required />
              </div>
            \`;
          } else if (shape === 'Circle') {
            // For a circle, just radius
            container.innerHTML = \`
              <div class="field-container">
                <label>Radius:</label>
                <input type="number" step="0.01" name="radius" required />
              </div>
            \`;
          } else if (shape === 'Parallelogram') {
            container.innerHTML = \`
              <div class="field-container">
                <label>Base:</label>
                <input type="number" step="0.01" name="base" required />
              </div>
              <div class="field-container">
                <label>Height:</label>
                <input type="number" step="0.01" name="height" required />
              </div>
            \`;
          } else if (shape === 'Trapezoid') {
            container.innerHTML = \`
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
            \`;
          } else {
            // If "--Choose an option--" is selected or anything else, do nothing
            container.innerHTML = '';
          }
        }
      </script>
    </body>
    </html>
  `;

  res.send(htmlForm);
});

// Handle form submission (POST request)
app.post('/submit', (req, res) => {
    // Basic user info
    const name = req.body.name;
    const email = req.body.email;
    const age = parseFloat(req.body.m_age);
    const shape = req.body.shape;
  
    // We'll compute or at least show what the user entered
    let resultMessage = `Hello, ${name}!<br>
                         Your email is: ${email}<br>
                         Age times 2: ${age * 2}<br>
                         Shape selected: ${shape}<br>`;
  
    // The shape-specific fields
    if (shape === 'Square') {
      const side = parseFloat(req.body.side);
      // e.g., area = side * side
      const area = side * side;
      resultMessage += `Side: ${side}<br>Area: ${area}<br>`;
    } else if (shape === 'Rectangle') {
      const length = parseFloat(req.body.length);
      const width = parseFloat(req.body.width);
      const area = length * width;
      resultMessage += `Length: ${length}, Width: ${width}<br>Area: ${area}<br>`;
    } else if (shape === 'Triangle') {
      const base = parseFloat(req.body.base);
      const height = parseFloat(req.body.height);
      const area = 0.5 * base * height;
      resultMessage += `Base: ${base}, Height: ${height}<br>Area: ${area}<br>`;
    } else if (shape === 'Circle') {
      const radius = parseFloat(req.body.radius);
      const area = Math.PI * radius * radius;
      resultMessage += `Radius: ${radius}<br>Area (πr²): ${area.toFixed(2)}<br>`;
    } else if (shape === 'Parallelogram') {
      const base = parseFloat(req.body.base);
      const height = parseFloat(req.body.height);
      const area = base * height;
      resultMessage += `Base: ${base}, Height: ${height}<br>Area: ${area}<br>`;
    } else if (shape === 'Trapezoid') {
      const base1 = parseFloat(req.body.base1);
      const base2 = parseFloat(req.body.base2);
      const height = parseFloat(req.body.height);
      const area = 0.5 * (base1 + base2) * height;
      resultMessage += `Base1: ${base1}, Base2: ${base2}, Height: ${height}<br>Area: ${area}<br>`;
    }
  
    // Return a simple HTML response
    res.send(`
      <html>
      <body>
        <h1>Submission Results</h1>
        <p>${resultMessage}</p>
        <p><a href="/">Go Back</a></p>
      </body>
      </html>
    `);
  });


app.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});