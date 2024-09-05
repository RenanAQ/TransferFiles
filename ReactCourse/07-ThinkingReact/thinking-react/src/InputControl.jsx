import { useState } from "react";
export default function InputControl() {
    const [category, setCategory] = useState("all");

  function handleCategoryChange(event) {
    setCategory(event.target.value);
  }
  return (
    <>
      <div>
        <input type="checkbox" id="fruits" name="fruits" />
        <label for="fruits">fruits</label>
      </div>

      <div>
        <input type="checkbox" id="vegetables" name="vegetables" />
        <label for="vegetables">vegetables</label>
      </div>
    </>
  );
}
