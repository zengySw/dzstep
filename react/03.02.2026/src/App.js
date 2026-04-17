import "./App.css";

import SideBar from "./components/sidebar";
import Header from "./components/header";
import Footer from "./components/footer";
import CategoryPage from "./components/page";

function App() {
  return (
    <div className="App">
      <Header />
      <main className="content">
        <SideBar>
          <nav class="catalog-nav">
            <ul class="catalog-list">
              <li class="catalog-item">
                <a href="#">Ноутбуки и компьютеры</a>
              </li>
              <li class="catalog-item">
                <a href="#">Смартфоны, ТВ и электроника</a>
              </li>
              <li class="catalog-item">
                <a href="#">Бытовая техника</a>
              </li>
              <li class="catalog-item">
                <a href="#">Товары для дома</a>
              </li>
              <li class="catalog-item">
                <a href="#">Инструменты и автотовары</a>
              </li>
              <li class="catalog-item">
                <a href="#">Детские товары</a>
              </li>
              <li class="catalog-item">
                <a href="#">Спорт и увлечения</a>
              </li>
              <li class="catalog-item">
                <a href="#">Одежда и обувь</a>
              </li>
            </ul>
          </nav>
        </SideBar>
        <CategoryPage />
      </main>
      <Footer />
    </div>
  );
}

export default App;
