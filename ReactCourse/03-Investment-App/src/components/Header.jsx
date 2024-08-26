export default function Header({ m_onChangeInput, m_userInput }) {
  return (
    <section id="user-input">
      <div className="input-group">
        <label>Initial Investment</label>
        <input
          type="number"
          value={m_userInput.initialInvest}
          onChange={(event) =>
            m_onChangeInput("initialInvest", event.target.value)
          }
          required
        ></input>
        <label>Annual Investment</label>
        <input
          type="number"
          value={m_userInput.annualInvest}
          onChange={(event) =>
            m_onChangeInput("annualInvest", event.target.value)
          }
          required
        ></input>
      </div>
      <div className="input-group">
        <label>Expected return</label>
        <input
          type="number"
          value={m_userInput.expectedReturn}
          onChange={(event) =>
            m_onChangeInput("expectedReturn", event.target.value)
          }
          required
        ></input>
        <label>Duration</label>
        <input
          type="number"
          value={m_userInput.duration}
          onChange={(event) => m_onChangeInput("duration", event.target.value)}
          required
        ></input>
      </div>
    </section>
  );
}
