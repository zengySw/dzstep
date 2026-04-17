import Header from './components/Header';
import Nav from './components/Nav';
import Main from './components/Main';
import Sidebar from './components/Sidebar';
import Footer from './components/Footer';

const App = () => {
  const navItems = [
    { label: "Домой", href: "#" },
    { label: "Компоненты", href: "#components" },
    { label: "Контакты", href: "#contacts" }
  ];

  const sidebarLinks = [
    { label: "Документация", href: "#docs" },
    { label: "Быстрый старт", href: "#start" },
    { label: "О проекте", href: "#about" }
  ];

  return (
    <>
      <Header version="v1.1" subtitle="Рефакторинг проекта на модули" />
      <Nav items={navItems} />
      <div className="layout">
        <Main />
        <Sidebar sections={sidebarLinks} />
      </div>
      <Footer />
    </>
  );
};

export default App;