import React from 'react';
import Header from '../components/Header';
import Footer from '../components/Footer';
import SideBar from '../components/SideBar';
import Main from '../components/Main';

const MainLayout = () => {
  return (
    <div className="app-shell">
      <Header />

      <div className="content-grid">
        <SideBar />
        <Main />
      </div>

      <Footer />
    </div>
  );
};

export default MainLayout;
