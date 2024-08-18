import { useState } from "react";
import { MY_FAMILY } from "../data";
import Section from "./Section";
import TabButton from "./TabButton";
import Tabs from "./Tabs";

export default function PrintingMyName() {
  const [selectedTopic, setSelectedTopic] = useState();

  //function to handle the button clicked
  function handleSelect(selectedButton) {
    setSelectedTopic(selectedButton);
  }
  //variable to display the info
  let tabContent = <p>Please select a member!</p>;
  //reassign the value of tabContent after click
  if (selectedTopic) {
    tabContent = (
      <div id="tab-content">
        <h3>Name: {MY_FAMILY[selectedTopic].name}</h3>
        <p>Age: {MY_FAMILY[selectedTopic].age}</p>
        <p>Favorite Food: {MY_FAMILY[selectedTopic].favFood}</p>
      </div>
    );
  }
  return (
    <Section title="Showing my family">
      <Tabs
        ButtonsContainer="menu"
        buttons={
          <>
            <TabButton
              isSelected={selectedTopic === "Renan"}
              onClick={() => handleSelect("Renan")}
            >
              Renan
            </TabButton>
            <TabButton
              isSelected={selectedTopic === "Geisiane"}
              onClick={() => handleSelect("Geisiane")}
            >
              Geisiane
            </TabButton>
            <TabButton
              isSelected={selectedTopic === "Emma"}
              onClick={() => handleSelect("Emma")}
            >
              Emma
            </TabButton>
            <TabButton
              isSelected={selectedTopic === "Lola"}
              onClick={() => handleSelect("Lola")}
            >
              Lola
            </TabButton>
          </>
        }
      >
        {tabContent}
      </Tabs>
    </Section>
  );
}
// export default function PrintingMyName({ name, age, favFood }) {
//     return (
//       <li>
//         <button></button>
//         My name is: {name}, I'm {age} years-old. My favorite food is: {favFood}!
//       </li>
//     );
//   }
