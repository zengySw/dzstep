export default function create_userRow(user, formatAge) {
  const tr = document.createElement("tr");

  if (user.age < 25) {
    tr.classList.add("young");
  }

  tr.innerHTML = `
    <td>${user.name}</td>
    <td>${formatAge(user.age)}</td>
    <td>${user.city}</td>
  `;

  return tr;
}