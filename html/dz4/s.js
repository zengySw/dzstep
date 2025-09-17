let name = prompt("Укажите свое имя:");
alert(Привет, ${name}!);
let date = new Date();
const year = prompt("Укажите год вашего рождения:");
if (year) {
  const age = 2025 - year;
  alert(Ваш возраст: ${age} лет);
}
let side = prompt("Укажите длину стороны квадрата:");
if (side) {
  const area = side * 4;
  alert(Периметр квадрата: ${area});
}
let radius = prompt("Укажите радиус круга:");
if (radius) {
    const area = Math.PI * radius * radius;
    alert(Площадь круга: ${area.toFixed(2)}); // toFixed(2) для округления до 2 знаков, я указал (2) в скобках и оно приняло это значение и теперь округляет до 2 знаков
}
let distance = prompt("Укажите расстояние в километрах между двумя городами:");
let time = prompt("Укажите время в часах, за которое вы хотите добраться:");
if (distance && time) {
    const speed = distance / time;
    alert(Вам нужно двигаться со скоростью: ${speed} км/ч);
}
let size = prompt("Укажите объем флешки в ГБ:");
if (size) {
    const sizeMB = size * 1024; 
    const files = Math.floor(sizeMB / 820);
    alert(На флешку вместится: ${files} файлов по 820 МБ);
}