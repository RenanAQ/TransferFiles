import React from 'react';
import logo from "../public/simulation-logo.png";

import { Header } from "./components/Header";
import ResultsControl from "./components/ResultsControl";
import RealData from "./components/RealData";
import {DynamicRealData} from "./components/DynamicRealData";
import { REAL_DATA } from "./services/RealData";

function App() {
  const tableEntries = Object.entries(REAL_DATA[0]);
  console.log("entries:",tableEntries)

  return (
    <>
      <Header logo={logo} />
      <RealData />
      <ResultsControl />
      <div>
      {tableEntries.map(([tableName, tableData]) => (
        <DynamicRealData key={tableName} tableName={tableName} tableData={tableData} />
      ))}
    </div>
    </>
  );
}

export default App;