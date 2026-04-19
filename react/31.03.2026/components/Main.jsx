import React from 'react';
import { Outlet } from '../router/SimpleRouter';

const Main = () => {
  return (
    <main className="main-content">
      <Outlet />
    </main>
  );
};

export default Main;
