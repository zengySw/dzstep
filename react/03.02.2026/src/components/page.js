import Card from "./card";
import list from "../details.json";

export default function CategoryPage() {
  return (
    <section
      className="catalog"
      style={{
        display: "flex",
        flexDirection: "row",
        flexWrap: "wrap",
        gap: "1px",
      }}
    >
      {list.data.map((item) => (
        <Card
          key={item.id}
          id={item.id}
          href={item.href}
          previewImg={item.images?.main}
          name={item.title}
          price={item.price}
        />
      ))}
    </section>
  );
}
