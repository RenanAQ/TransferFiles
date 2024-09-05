import { useState } from "react";
import { styled } from "styled-components";
import { PRICES_NFL } from "../services/NFL-Prices";

export default function ResultsControl() {
  const numberOfKeys = Object.keys(PRICES_NFL).length;
  const lowestPrices = {};

  for (const team in PRICES_NFL) {
    const prices = Object.values(PRICES_NFL[team]);
    const lowestPrice = Math.min(...prices);
    lowestPrices[team] = lowestPrice;
  }
  console.log(lowestPrices);
  const [checkboxState, setCheckboxState] = useState(false);
  const ControlDiv = styled.div`
    padding: 1rem;
    max-width: 30rem;
    margin: 2rem auto;
    border-radius: 4px;
    background-color: ${checkboxState ? "red" : "green"};
    & p {
      color: ${checkboxState ? "blue" : "black"};
      text-transform: ${checkboxState ? "uppercase" : "lowercase"};
    }
  `;
  return (
    <>
      <div id="user-input">
        <label>Simulation</label>
        <input type="number" placeholder="0" />
      </div>
      <ControlDiv>
        <label>Testing styled components</label>
        <input
          type="checkbox"
          onClick={() => setCheckboxState(!checkboxState)}
        />
        <h1>NFL PRICES</h1>
        <p>Total teams checked: {Object.keys(PRICES_NFL).length}</p>
        <p>Lowest price for:</p>
        <ul>
          {Object.keys(lowestPrices).map((team) => (
            <li key={team}>
              {team}: {lowestPrices[team]}
            </li>
          ))}
        </ul>
      </ControlDiv>
    </>
  );
}
