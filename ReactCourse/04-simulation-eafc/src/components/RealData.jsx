import { REAL_DATA } from "../services/RealData";

export default function RealData() {
  const primeiroTime = REAL_DATA[0]["Table 0"][0];
  const relegated1 = REAL_DATA[0]["Table 0"][17];
  const relegated2 = REAL_DATA[0]["Table 0"][18];
  const relegated3 = REAL_DATA[0]["Table 0"][19];
  
  return (
    <table id="result">
      <thead>
        <tr>
          <th>Simulation #</th>
          <th>Champion</th>
          <th>Relegated #1</th>
          <th>Relegated #2</th>
          <th>Relegated #3</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>Real data</td>
          <td>{primeiroTime.Club}</td>
          <td>{relegated1.Club}</td>
          <td>{relegated2.Club}</td>
          <td>{relegated3.Club}</td>
        </tr>
      </tbody>
    </table>
  );
}

//simulacao: Valor real
// primeiro colocado
// rebaixados {18, 19,20}

//# simulacao | First Place | Relegated #1 | Relegated #2 | Relegated #3 |
