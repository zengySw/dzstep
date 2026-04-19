import React from 'react';

const HomePage = () => {
  return (
    <section className="page-card">
      <h2>Home</h2>
      <p>This is the master page. Main renders current route through Outlet.</p>

      <ul className="check-list">
        <li>Header component is ready.</li>
        <li>Footer component is ready.</li>
        <li>SideBar component is ready.</li>
        <li>Product card component is ready.</li>
        <li>Navigation and routing are ready.</li>
        <li>Loader reads data from JSON file.</li>
      </ul>
    </section>
  );
};

export default HomePage;
