calculations = (req, res) => {
  let m_area; //scoping problem
  const shapeSelected = req.body.shape;
  
  switch (shapeSelected) {
    case "Square":
        const side = parseFloat(req.body.side);
        m_area = side * side;
      break;
    case "Parallelogram":
        const baseP = parseFloat(req.body.base);
        const heightP = parseFloat(req.body.height);
        m_area = (baseP * heightP);
        break;
    case "Circle":
        const radius = parseFloat(req.body.radius);
        m_area = radius * radius * 3.1415;
        break;
    case "Triangle":
        const base = parseFloat(req.body.base);
        const height = parseFloat(req.body.height);
        m_area = (base * height) / 2;
        break;
    case "Trapezoid":
        const base1 = parseFloat(req.body.base1);
        const base2 = parseFloat(req.body.base2);
        const height1 = parseFloat(req.body.height);
        m_area = (base1 + base2) * height1 / 2;
        break;
    case "Rectangle":
        const length = parseFloat(req.body.length);
        const width = parseFloat(req.body.width);
        m_area = length * width;
        break;
    default:
      m_area = "Still learning";
      break;
  }

  res.render("result", {
    m_pageTitle: "Calc Result",
    m_title: req.body.title,
    m_shape: shapeSelected,
    m_area: m_area,
  });
};

module.exports = calculations;
