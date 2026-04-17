const Sidebar = ({ sections }) => (
  <aside className="sidebar">
    <h3>Боковая панель</h3>
    <ul>
      {sections.map((s, i) => (
        <li key={i}>
          <a href={s.href}>{s.label}</a>
        </li>
      ))}
    </ul>
  </aside>
);

export default Sidebar;