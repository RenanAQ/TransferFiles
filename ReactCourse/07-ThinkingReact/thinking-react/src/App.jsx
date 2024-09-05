import { useState } from "react";
import "./App.css";
import { DisplayList } from "./DisplayList";
import InputControl from "./InputControl";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      <h1>Market List</h1>

      <div>
        <InputControl />
        <DisplayList category={category} />
      </div>
    </>
  );
}

export default App;
