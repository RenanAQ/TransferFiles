export default function Results({
  initialInvest,
  annualInvest,
  expectedReturn,
  duration,
}) {
  return (
    <li id="result">
      <thead>
        <tr>
          <th>Year</th>
          <th>Investment Value</th>
          <th>Interest Year</th>
          <th>Total Interest</th>
          <th>Invested Capital</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>initialInvest</td>
          <td>annualInvest</td>
          <td>expectedReturn</td>
          <td>duration</td>
        </tr>
      </tbody>
    </li>
  );
}
