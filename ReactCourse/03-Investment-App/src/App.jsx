import { useState } from "react";

import Header from "./components/Header";
import Results from "./components/Results";

function App() {
  const [userInput, setUserInput] = useState({
    initialInvest: 10000,
    annualInvest: 1200,
    expectedReturn: 6,
    duration: 10,
  });

  console.log("Debuging:")
  console.log(`initial: ${userInput.initialInvest}`)
  console.log(`annual: ${userInput.annualInvest}`)
  console.log(`expected: ${userInput.expectedReturn}`)
  console.log(`duration: ${userInput.duration}`)
  
  const inputIsValid = userInput.duration >= 1;

  function handleUserInput(inputID, newValue) {
    setUserInput((prevUserInput) => {
      return {
        ...prevUserInput,
        [inputID]: +newValue,
      };
    });
  }
  return (
    <>
      <Header userInput={userInput} onChange={handleUserInput} />
      {!inputIsValid && (
        <p className="center">Duration must be greater than zero</p>
      )}
      {inputIsValid && <Results m_input={userInput} />}
    </>
  );
}
export default App;
