import create_userRow from "./UserRow.js";

export default function create_userTable(users, formatAge) {
  if (!users.length) {
    const p = document.createElement("p");
    p.textContent = "Пользователи отсутствуют";
    return p;
  }

  const table = document.createElement("table");

  const thead = document.createElement("thead");
  thead.innerHTML = `
    <tr>
      <th>Имя</th>
      <th>Возраст</th>
      <th>Город</th>
    </tr>
  `;

  const tbody = document.createElement("tbody");

  users.forEach(user => {
    const row = create_userRow(user, formatAge);
    tbody.append(row);
  });

  table.append(thead, tbody);

  return table;
}