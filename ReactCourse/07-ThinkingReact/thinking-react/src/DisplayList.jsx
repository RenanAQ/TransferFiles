import { MARKET } from "./util/data";

export function DisplayList({ category = "all" }) {
  const filteredMarket = category === "all" 
    ? MARKET 
    : MARKET.filter(item => item.category === category);

  return (
    <ul>
      {filteredMarket.map((item) => (
        <li key={item.name}>{item.name}</li>
      ))}
    </ul>
  );
}