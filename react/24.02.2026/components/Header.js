const Header = ({ version, subtitle }) => (
  <header>
    <h1 style={{ margin: 0 }}>
      MyApp <span className="badge">{version}</span>
    </h1>
    <div className="muted">{subtitle}</div>
  </header>
);

export default Header;