const express = require('express');
const app = express();

// Middleware to parse application/x-www-form-urlencoded (from HTML forms)
app.use(express.urlencoded({ extended: true }));

// Display the form (GET request)
app.get('/', (req, res) => {
  const htmlForm = `
    <form action="/submit" method="POST">
      <label>Name:</label>
      <input type="text" name="name" />
      <br>
      <label>Email:</label>
      <input type="email" name="email" />
      <br>
      <label>Age:</label>
      <input type="number" step="0.01" name="m_age" />
      <br>
      <label for="shape">Select the shape you want to calculate</label>
      <select name="shape" id="shape"onchange="showSelectedShape(this.value)">
          <option value="">--Choose an option--</option>
          <option value="Square">Square</option>
          <option value="Triangle">Triangle</option>
          <option value="Rectangle">Rectangle</option>
          <option value="Circle">Circle</option>
          <option value="Parallelogram">Parallelogram</option>
          <option value="Trapezoid">Trapezoid</option>
      </select>   
      <button type="submit">Submit</button>
    </form>
  `;
  res.send(htmlForm);
});

// Handle form submission (POST request)
app.post('/submit', (req, res) => {
  // req.body will contain the form data
  const name = req.body.name;     // e.g., "John"
  const email = req.body.email;   // e.g., "john@example.com"
  const age = req.body.m_age;
  const shape = req.body.shape;

  // You can now store these in a database, do some logic, etc.
  console.log('Name:', name);
  console.log('Email:', email);

  // Send back a response
  res.send(`Thank you, ${name}. Shape: ${shape} Your email is ${email}. Age times 2: ${age*2}`);
});

app.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});