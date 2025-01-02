calculations = (req, res) => {
  let m_area; //scoping problem
  const shapeSelected = req.body.shape;
  const value1 = req.body.value1;
  const value2 = req.body.value2;
  const value3 = req.body.value3;
  switch (shapeSelected) {
    case "Square":
    case "Parallelogram":
      m_area = value1 * value2;
      break;
    case "Circle":
      m_area = value1 * value1 * 3.1415;
      break;
    case "Triangle":
      m_area = (value1 * value2) / 2;
      break;
    case "Trapezoid":
        m_area = (value1+value2)*value3/2;
        break;
    default:
      m_area = "Still learning";
      break;
  }

  res.render("result", {
    m_pageTitle: "Calc Result",
    m_title: req.body.title,
    m_shape: shapeSelected,
    m_value1: value1,
    m_value2: value2,
    m_value3: value3,
    m_area: m_area,
  });
};

module.exports = calculations;
