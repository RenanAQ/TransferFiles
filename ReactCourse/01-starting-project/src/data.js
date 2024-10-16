import componentsImg from "./assets/components.png";
import propsImg from "./assets/config.png";
import jsxImg from "./assets/jsx-ui.png";
import stateImg from "./assets/state-mgmt.png";

export const CORE_CONCEPTS = [
  {
    image: componentsImg,
    title: "Components",
    description:
      "The core UI building block - compose the user interface by combining multiple components.",
  },
  {
    image: jsxImg,
    title: "JSX",
    description:
      "Return (potentially dynamic) HTML(ish) code to define the actual markup that will be rendered.",
  },
  {
    image: propsImg,
    title: "Props",
    description:
      "Make components configurable (and therefore reusable) by passing input data to them.",
  },
  {
    image: stateImg,
    title: "State",
    description:
      "React-managed data which, when changed, causes the component to re-render & the UI to update.",
  },
];

export const MY_FAMILY = {
  Renan: {
    name: "Renan",
    age: 28,
    favFood: "Hamburguer"
  },
  Geisiane:{
    name: "Geisiane",
    age: 28,
    favFood: "Sushi"
  },
  Emma:{
    name: "Emma",
    age: 9,
    favFood: "Banana"
  },
  Lola:{
    name: "Lola",
    age: 8,
    favFood: "Chicken"
  }
};