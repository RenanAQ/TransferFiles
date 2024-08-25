import Header from "./components/Header";
import Results from "./components/Results";

function App() {
  return (
    <>
      <Header />
      <Results
        initialInvest={""}
        annualInvest={""}
        expectedReturn={""}
        duration={""}
      />
    </>
  );
}

export default App;
