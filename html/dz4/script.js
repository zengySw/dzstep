



// let age = parseInt(prompt("Введите возраст"));
// if (age >= 0 && age <= 120) { 
//     if (age >= 0 && age <= 2) {alert("kid")}
//     else if (age >= 12 && age <= 18) {alert("teenager")} 
//     else if (age >= 18 && age <= 60) {alert("adult")}
//     else if (age >= 60 && age <= 120) {alert("old")};
    
// }
// else alert("Некорректный возраст");



let n = parseInt(prompt("Введите число"));
switch (n) {
    case 1: alert("!"); break;
    case 2: alert("@"); break;
    case 3: alert("#"); break;
    case 4: alert("$"); break;
    case 5: alert("%"); break;
    case 6: alert("^"); break;
    case 7: alert("&"); break;
    case 8: alert("*"); break;
    case 9: alert("("); break;
    case 0: alert(")"); break;
}
alert("Модуль = " + n);



// let h = parseInt(prompt("Часы (0–23)"));
// let m = parseInt(prompt("Минуты (0–59)"));
// let s = parseInt(prompt("Секунды (0–59)"));

// if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
// alert("Время корректное");
// else
// alert("Некорректное время");



// let x = parseInt(prompt("Введите X"));
// let y = parseInt(prompt("Введите Y"));

// if (x == 0 && y == 0) alert("Начало координат");
// else if (x == 0) alert("На оси Y");
// else if (y == 0) alert("На оси X");
// else if (x > 0 && y > 0) alert("I четверть");
// else if (x < 0 && y > 0) alert("II четверть");
// else if (x < 0 && y < 0) alert("III четверть");
// else alert("IV четверть");



// let m = parseInt(prompt("Введите номер месяца (1-12)"));
// switch (m) {
// case 1: alert("Январь"); break;
// case 2: alert("Февраль"); break;
// case 3: alert("Март"); break;
// case 4: alert("Апрель"); break;
// case 5: alert("Май"); break;
// case 6: alert("Июнь"); break;
// case 7: alert("Июль"); break;
// case 8: alert("Август"); break;
// case 9: alert("Сентябрь"); break;
// case 10: alert("Октябрь"); break;
// case 11: alert("Ноябрь"); break;
// case 12: alert("Декабрь"); break;
// default: alert("Нет такого месяца");
// }



// let a = Number(prompt("Введите первое число"));
// let b = Number(prompt("Введите второе число"));
// let sign = prompt("Введите знак (+ - * /)");

// switch (sign) {
// case "+": alert(a + b); break;
// case "-": alert(a - b); break;
// case "*": alert(a * b); break;
// case "/": alert(b != 0 ? a / b : "Деление на ноль!"); break;
// default: alert("Неверный знак");
// }




// let a = parseInt(prompt("Введите первое число"));
// let b = parseInt(prompt("Введите второе число"));
// alert(a > b ? a : b);



// let n = parseInt(prompt("Введите число"));
// alert(n % 5 == 0 ? "Кратно 5" : "Не кратно 5");



// let planet = prompt("Введите название планеты");
// alert((planet == "Земля" || planet == "земля") ? "Привет, землянин!" : "Привет, инопланетянин!");