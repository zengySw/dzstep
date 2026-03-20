import "./style.css";
import create_gallery from "./Gallery.js";

const images = [
  { id: 1, url: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR39iGG5an70vyRJijnMXRHtohS_9foYxrOAg&s", title: "Фото 1", author: "Ирина" },
  { id: 2, url: "https://img.freepik.com/free-photo/expressive-redhead-bearded-man_176420-32277.jpg?semt=ais_hybrid&w=740&q=80", title: "Фото 2", author: "Артём" },
  { id: 3, url: "https://i.stena.ee/21/2022-02-06_080725.jpg", title: "Фото 3", author: "Кирилл" },
];


const h1 = document.createElement("h1");
h1.textContent = "Галерея";

document.querySelector("#app").append(h1, create_gallery(images));