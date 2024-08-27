export default function Header({ onChange, userInput }) {

  return (
    <section id="user-input">
      <div className="input-group">
        <label>Initial Investment</label>
        <input
          type="number"
          value={userInput.initialInvest}
          onChange={(event) =>
            onChange("initialInvest", event.target.value)
          }
          required
        ></input>
        <label>Annual Investment</label>
        <input
          type="number"
          value={userInput.annualInvest}
          onChange={(event) =>
            onChange("annualInvest", event.target.value)
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
