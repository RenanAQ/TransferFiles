import { useState } from "react";

export default function Player({ initialName, symbol }) {
    const [playerName, setPlayerName] = useState(initialName);
    const [isEditing, setIsEditing] = useState(false);

  //function to handle the button clicked
  function handleEditClick() {
    setIsEditing((editing)=>!editing); //best practice
  }
  function handleChange(m_event){ //listener
    setPlayerName(m_event.target.value);
  } 
  //variable to change the state
  let editablePlayerName = <span className="player-name">{playerName}</span>;
  let btnCaption = "Edit";
  //statement to change the variable if button clicked
  if (isEditing) {
    editablePlayerName = <input type="text" required value={playerName} onChange={handleChange} />;
    btnCaption = "Save";
  }
  //main function
  return (
    <li>
      <span className="player">
        {editablePlayerName}
        <span className="player-symbol">{symbol}</span>
      </span>
      <button onClick={handleEditClick}>{btnCaption}</button>
    </li>
  );
}
