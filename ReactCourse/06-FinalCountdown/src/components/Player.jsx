import { useState, useRef } from "react";

export default function Player() {
  const playerName = useRef();
  const [enteredPlayerName, setEnteredPlayerName] = useState(null);
  
  // const [submitPlayerName, setSubmitPlayerName] = useState(false); //Not necessary because useRef instead
  // function handleChange(e) { //Not necessary because useRef instead
  //   // setSubmitPlayerName(false); 
  //   setEnteredPlayerName(e.target.value);
  // }
  function handleClick() {
    setEnteredPlayerName(playerName.current.value);
    playerName.current.value = ""; // Reset input field after submission
  }
  return (
    <section id="player">
      <h2>Welcome {enteredPlayerName ?? "unknown entity"}</h2>
      <p>
        <input
          type="text"
          ref={playerName}
          // onChange={handleChange} //Not necessary because useRef instead
          // value={enteredPlayerName} //Not necessary because useRef instead
        />
        <button onClick={handleClick}>Set Name</button>
      </p>
    </section>
  );
}
