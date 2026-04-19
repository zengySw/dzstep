import React from 'react';
import { Link } from '../router/SimpleRouter';

const Header = () => {
  return (
    <header className="app-header">
      <div className="brand-block">
        <h1>Shop Master Page</h1>
        <p>Header + Footer + SideBar + Main(Outlet) + Product card</p>
      </div>

      <nav className="top-nav" aria-label="Main navigation">
        <Link to="/">Home</Link>
        <Link to="/products">Products</Link>
        <Link to="/contacts">Contacts</Link>
      </nav>
    </header>
  );
};

export default Header;
