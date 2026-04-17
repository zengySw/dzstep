const Nav = ({ items }) => (
  <nav>
    <strong>Навигация: </strong>
    {items.map((item, i) => (
      <a key={i} href={item.href} style={{ marginRight: 12 }}>
        {item.label}
      </a>
    ))}
  </nav>
);

export default Nav;