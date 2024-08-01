export default function CoreConcepts({ image, title, description }) {
    //Destructuring the CORE_CONCEPTS object
    return (
      <li>
        <img src={image} alt={title} />
        <h3>{title}</h3>
        <p>{description}</p>
      </li>
    );
  }