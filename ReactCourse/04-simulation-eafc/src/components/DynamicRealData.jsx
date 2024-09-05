export const DynamicRealData = ({ tableName, tableData }) => (
  <div>
    <h2>{tableName}</h2>
    <table border="1">
      <thead>
        <tr>
          {Object.keys(tableData[0]).map((key) => (
            <th key={key}>{key}</th>
          ))}
        </tr>
      </thead>
      <tbody>
        {tableData.map((row, index) => (
          <tr key={index}>
            {Object.values(row).map((value, i) => (
              <td key={i}>{value}</td>
            ))}
          </tr>
        ))}
      </tbody>
    </table>
  </div>
);
