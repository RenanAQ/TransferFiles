//Importing
import Header from "./components/Header/Header.jsx";
import CoreConcepts from "./components/CoreConcepts.jsx";
import Examples from "./components/Examples.jsx";
import PrintingMyName from "./components/PrintingMyName.jsx";

//main function App
function App() {
  //exectution of the main function App
  return (
    <>
      <Header />
      <main>
        <CoreConcepts/>
        <Examples/>
      </main>
      <PrintingMyName/>
    </>
  );
}

export default App;
