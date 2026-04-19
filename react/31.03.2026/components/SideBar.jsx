import React from 'react';
import { Link } from '../router/SimpleRouter';

const SideBar = () => {
  return (
    <aside className="sidebar">
      <h2>SideBar</h2>

      <ul className="side-links">
        <li>
          <Link to="/">Main page</Link>
        </li>
        <li>
          <Link to="/products">Products from JSON</Link>
        </li>
        <li>
          <Link to="/contacts">Contacts</Link>
        </li>
      </ul>

      <div className="sidebar-note">
        <p>Data source: <code>src/details.json</code></p>
        <p>Loading logic: custom route loader.</p>
      </div>
    </aside>
  );
};

export default SideBar;
