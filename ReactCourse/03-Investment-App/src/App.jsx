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

  userInput.annualInvest

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
      <Header m_userInput={userInput} m_onChangeInput={handleUserInput} />
      {!inputIsValid && (
        <p className="center">Duration must be greater than zero</p>
      )}
      {inputIsValid && <Results m_input={userInput} />}
    </>
  );
}

export default App;
