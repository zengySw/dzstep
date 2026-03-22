import "./style.css";
import create_userTable from "./UserTable.js";

const users = [
  { id: 1, name: "Оля", age: 20, city: "Киев" },
  { id: 2, name: "Игорь", age: 30, city: "Одесса" },
  { id: 3, name: "Лена", age: 25, city: "Львов" }
];

function formatAge(age) {
  return `${age} лет`;
}

const h2 = document.createElement("h2");
h2.textContent = "Пользователи";

document
  .querySelector("#app")
  .append(h2, create_userTable(users, formatAge));