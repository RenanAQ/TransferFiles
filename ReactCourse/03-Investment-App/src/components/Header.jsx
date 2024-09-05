export default function Header({ onChange, userInput }) {

  return (
    <section id="user-input">
      <div className="input-group">
        <label>Initial Investment</label>
        <input
          type="number"
          value={userInput.initialInvestment}
          onChange={(event) =>
            onChange("initialInvestment", event.target.value)
          }
          required
        ></input>
        <label>Annual Investment</label>
        <input
          type="number"
          value={userInput.annualInvestment}
          onChange={(event) =>
            onChange("annualInvestment", event.target.value)
          }
          required
        ></input>
      </div>
      <div className="input-group">
        <label>Expected return</label>
        <input
          type="number"
          value={userInput.expectedReturn}
          onChange={(event) =>
            onChange("expectedReturn", event.target.value)
          }
          required
        ></input>
        <label>Duration</label>
        <input
          type="number"
          value={userInput.duration}
          onChange={(event) => onChange("duration", event.target.value)}
          required
        ></input>
      </div>
    </section>
  );
}
