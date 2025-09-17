// function task1() {
//   let age = parseInt(prompt("Введите возраст:"));
//   if (age >= 0 && age <= 2) {
//     alert("Вы ребенок");
//   } else if (age >= 3 && age <= 11) {
//     alert("Вы ребенок постарше");
//   } else if (age >= 12 && age <= 17) {
//     alert("Вы подросток");
//   } else if (age >= 18 && age <= 59) {
//     alert("Вы взрослый");
//   } else if (age >= 60) {
//     alert("Вы пенсионер");
//   } else {
//     alert("Некорректный возраст");
//   }
// }

// function task2() {
//   let num = parseInt(prompt("Введите число от 0 до 9:"));
//   switch (num) {
//     case 0: alert(")"); break;
//     case 1: alert("!"); break;
//     case 2: alert("@"); break;
//     case 3: alert("#"); break;
//     case 4: alert("$"); break;
//     case 5: alert("%"); break;
//     case 6: alert("^"); break;
//     case 7: alert("&"); break;
//     case 8: alert("*"); break;
//     case 9: alert("("); break;
//     default: alert("Нужно число от 0 до 9");
//   }
// }

// function task3() {
//   let num = prompt("Введите трехзначное число:");
//   if (num.length != 3) {
//     alert("Это не трехзначное число");
//     return;
//   }
//   if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) {
//     alert("Есть одинаковые цифры");
//   } else {
//     alert("Все цифры разные");
//   }
// }

// function task4() {
//   let year = parseInt(prompt("Введите год:"));
//   if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
//     alert("Високосный год");
//   } else {
//     alert("Не високосный год");
//   }
// }

// function task5() {
//   let num = prompt("Введите пятизначное число:");
//   if (num[0] == num[4] && num[1] == num[3]) {
//     alert("Палиндром");
//   } else {
//     alert("Не палиндром");
//   }
// }

// function task6() {
//   let usd = parseFloat(prompt("Введите сумму в USD:"));
//   let to = prompt("В какую валюту? (EUR, UAN, AZN)");

//   switch (to) {
//     case "EUR": alert(usd * 0.9 + " EUR"); break;
//     case "UAN": alert(usd * 40 + " UAN"); break;
//     case "AZN": alert(usd * 1.7 + " AZN"); break;
//     default: alert("Неизвестная валюта");
//   }
// }

// function task7() {
//   let sum = parseFloat(prompt("Введите сумму покупки:"));
//   let discount = 0;
//   if (sum >= 200 && sum < 300) discount = 3;
//   if (sum >= 300 && sum < 500) discount = 5;
//   if (sum >= 500) discount = 7;
//   let result = sum - (sum * discount / 100);
//   alert("Скидка " + discount + "%. К оплате: " + result);
// }

// function task8() {
//   let L = parseFloat(prompt("Введите длину окружности:"));
//   let P = parseFloat(prompt("Введите периметр квадрата:"));
//   let D = L / 3.14;
//   let a = P / 4;
//   if (D <= a) {
//     alert("Окружность помещается");
//   } else {
//     alert("Окружность не помещается");
//   }
// }

// function task9() {
//   let score = 0;

//   let q1 = prompt("Столица Франции? (Париж/Берлин/Рим)");
//   switch (q1) {
//     case "Париж": score += 2; break;
//   }

//   let q2 = prompt("2+2*2=? (6/4/8)");
//   switch (q2) {
//     case "6": score += 2; break;
//   }

//   let q3 = prompt("Язык в браузере? (Python/Java/JavaScript)");
//   switch (q3) {
//     case "JavaScript": score += 2; break;
//   }

//   alert("Ваш результат: " + score);
// }

function task10() {
  let d = parseInt(prompt("День:"));
  let m = parseInt(prompt("Месяц:"));
  let y = parseInt(prompt("Год:"));

  let daysInMonth;
  switch (m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      daysInMonth = 31; break;
    case 4: case 6: case 9: case 11:
      daysInMonth = 30; break;
    case 2:
      if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        daysInMonth = 29;
      } else {
        daysInMonth = 28;
      }
      break;
    default:
      alert("Некорректный месяц");
      return;
  }

  d++;
  if (d > daysInMonth) {
    d = 1;
    m++;
    if (m > 12) {
      m = 1;
      y++;
    }
  }

  alert("Следующая дата: " + d + "." + m + "." + y);
}
