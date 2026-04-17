import React, { useContext } from 'react';
import { ThemeContext, ThemeProvider } from './context/ThemeContext';
import PricingTable from './components/PricingTable';
import './theme.css';

const AppContent = () => {
  const { theme, toggleTheme } = useContext(ThemeContext);

  return (
    <div className="app">
      <header style={{ textAlign: 'center', padding: '20px' }}>
        <button onClick={toggleTheme}>
          Переключить на {theme === 'light' ? 'dark' : 'light'} тему
        </button>
      </header>
      <PricingTable />
    </div>
  );
};

const App = () => (
  <ThemeProvider>
    <AppContent />
  </ThemeProvider>
);

export default App;