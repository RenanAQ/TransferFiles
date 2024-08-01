import { CORE_CONCEPTS } from "./data.js";
import Header from "./components/Header/Header.jsx";
import CoreConcepts from "./components/CoreConcepts.jsx";
import PrintingMyName from "./components/PrintingMyName.jsx";
import { MY_FAMILY } from "./data.js";
import TabButton from "./components/TabButton.jsx";



function App() {
  return (
    <div>
      <Header />
      <main>
        <section id="core-concepts">
          <h2>Core Concepts</h2>
          <ul>
            <CoreConcepts //THIS IS THE LONGEST VERSION
              title={CORE_CONCEPTS[0].title}
              description={CORE_CONCEPTS[0].description}
              image={CORE_CONCEPTS[0].image}
            />
            {/*This is the shortest version*/}
            <CoreConcepts {...CORE_CONCEPTS[1]} />
            <CoreConcepts {...CORE_CONCEPTS[2]} />
            <CoreConcepts {...CORE_CONCEPTS[3]} />
          </ul>
        </section>
        <section id="examples">
          <h2>Examples</h2>
          <menu>
            <TabButton>Components</TabButton>
            <TabButton>JSX</TabButton>
            <TabButton>Props</TabButton>
            <TabButton>States</TabButton>
          </menu>
        </section>
      </main>
      <PrintingMyName {...MY_FAMILY[0]} />
      <PrintingMyName {...MY_FAMILY[1]} />
      <PrintingMyName {...MY_FAMILY[2]} />
      <PrintingMyName {...MY_FAMILY[3]} />
    </div>
  );
}

export default App;
