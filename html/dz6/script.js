// function task1() {
//     const startInput = prompt("1. Введіть початок діапазону:");
//     const endInput = prompt("1. Введіть кінець діапазону:");

//     const start = parseInt(startInput);
//     const end = parseInt(endInput);

//     if (isNaN(start) || isNaN(end)) {
//         console.log("1. Некоректний ввід.");
//         return;
//     }

//     let totalSum = 0;

//     for (let i = start; i <= end; i++) {
//         totalSum = totalSum + i;
//     }

//     console.log(`1. Сума чисел у діапазоні від ${start} до ${end}: ${totalSum}`);
// }


// function task2() {
//     let a = parseInt(prompt("2. Введіть перше число для НСД:"));
//     let b = parseInt(prompt("2. Введіть друге число для НСД:"));

//     if (isNaN(a) || isNaN(b) || (a === 0 && b === 0)) {
//         console.log("2. Введено некоректні дані.");
//         return;
//     }

//     let num1 = Math.abs(a);
//     let num2 = Math.abs(b);

//     while (num2 !== 0) {
//         let remainder = num1 % num2;
//         num1 = num2;
//         num2 = remainder;
//     }

//     console.log(`2. Найбільший спільний дільник: ${num1}`);
// }


// function task3() {
//     const number = parseInt(prompt("3. Введіть число, щоб знайти його дільники:"));

//     if (isNaN(number) || number <= 0) {
//         console.log("3. Введіть додатне число.");
//         return;
//     }

//     let output = "3. Дільники: ";

//     for (let i = 1; i <= number; i++) {
//         if (number % i === 0) {
//             output = output + i + ", ";
//         }
//     }

//     console.log(output.slice(0, -2));
// }


// function task4() {
//     let input = prompt("4. Введіть число, щоб порахувати його цифри:");

//     let number = Math.abs(parseInt(input));

//     if (isNaN(number)) {
//         console.log("4. Введено некоректні дані.");
//         return;
//     }

//     if (number === 0) {
//         console.log("4. Кількість цифр: 1");
//         return;
//     }

//     let count = 0;

//     while (number > 0) {
//         number = Math.floor(number / 10);
//         count++;
//     }

//     console.log(`4. Кількість цифр у числі ${input}: ${count}`);
// }


// function task5() {
//     console.log("5. Введіть 10 чисел для підрахунку статистики.");
//     let posCount = 0;
//     let negCount = 0;
//     let zeroCount = 0;
//     let evenCount = 0;
//     let oddCount = 0;

//     for (let i = 1; i <= 10; i++) {
//         const input = prompt(`5. Введіть число №${i} з 10:`);
//         const num = parseInt(input);

//         if (isNaN(num)) {
//             console.log(`Помилка введення на кроці ${i}. Пропускаємо.`);
//             continue;
//         }

//         if (num > 0) {
//             posCount++;
//         } else if (num < 0) {
//             negCount++;
//         } else {
//             zeroCount++;
//         }

//         if (num % 2 === 0) {
//             evenCount++;
//         } else {
//             oddCount++;
//         }
//     }

//     console.log("5. Статистика чисел:");
//     console.log(`   Позитивних: ${posCount}`);
//     console.log(`   Негативних: ${negCount}`);
//     console.log(`   Нулів: ${zeroCount}`);
//     console.log(`   Парних: ${evenCount}`);
//     console.log(`   Непарних: ${oddCount}`);
// }


// function task6() {
//     console.log("6. Запущено зациклений калькулятор.");
//     let continueCalculating = false;

//     do {
//         const num1 = parseFloat(prompt("6. Введіть перше число:"));
//         const operator = prompt("6. Введіть оператор (+, -, *, /):");
//         const num2 = parseFloat(prompt("6. Введіть друге число:"));
//         let result = 0;
//         let valid = true;

//         if (isNaN(num1) || isNaN(num2)) {
//             console.log("6. Помилка: Введено некоректні числа.");
//             valid = false;
//         } else {
//             switch (operator) {
//                 case '+':
//                     result = num1 + num2;
//                     break;
//                 case '-':
//                     result = num1 - num2;
//                     break;
//                 case '*':
//                     result = num1 * num2;
//                     break;
//                 case '/':
//                     if (num2 === 0) {
//                         console.log("6. Помилка: Ділення на нуль!");
//                         valid = false;
//                     } else {
//                         result = num1 / num2;
//                     }
//                     break;
//                 default:
//                     console.log("6. Невірний оператор.");
//                     valid = false;
//             }
//         }

//         if (valid) {
//             console.log(`6. Результат: ${num1} ${operator} ${num2} = ${result}`);
//         }

//         continueCalculating = confirm("6. Бажаєте вирішити ще один приклад?");

//     } while (continueCalculating);

//     console.log("6. Калькулятор завершив роботу.");
// }


// function task7() {
//     let numberStr = prompt("7. Введіть число:");
//     let shiftInput = prompt("7. На скільки цифр його зсунути?");
//     let shift = parseInt(shiftInput);

//     if (isNaN(shift) || shift < 0 || !numberStr) {
//         console.log("7. Некоректні дані.");
//         return;
//     }

//     let digits = String(numberStr);
//     const len = digits.length;

//     const actualShift = shift % len;

//     for (let i = 0; i < actualShift; i++) {
//         const firstDigit = digits[0];
//         digits = digits.slice(1) + firstDigit;
//     }

//     console.log(`7. Початкове число: ${numberStr}`);
//     console.log(`   Зсув на ${shift} дає: ${digits}`);
// }


// function task8() {
//     const days = ["Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота", "Неділя"];
//     let dayIndex = 0;
//     let continueLoop;

//     do {
//         const currentDay = days[dayIndex % 7];

//         continueLoop = confirm(`8. День тижня: ${currentDay}. Хочете побачити наступний день?`);

//         dayIndex++;

//     } while (continueLoop);

//     console.log("8. Вивід днів тижня завершено.");
// }


// function task9() {
//     console.log("\n--- 9. Таблиця множення (2x1 до 9x10) ---");

//     for (let i = 2; i <= 9; i++) {
//         console.log(`\nТаблиця множення для числа ${i}:`);

//         for (let j = 1; j <= 10; j++) {
//             const result = i * j;
//             console.log(`   ${i} * ${j} = ${result}`);
//         }
//     }
// }


function task10() {
    console.log("\n--- 10. Гра «Угадай число» (від 0 до 100) ---");
    alert("10. Загадайте число від 0 до 100. Комп'ютер спробує його відгадати.");

    let min = 0;
    let max = 100;
    let guess;
    let result;
    let attempts = 0;

    while (true) {
        attempts++;
        guess = Math.floor((min + max) / 2);

        if (min > max) {
            console.log(`10. Помилка: Ви, ймовірно, помилилися у відповідях. Спроба ${attempts}.`);
            break;
        }

        result = prompt(`10. Ваше число ${guess}? Введіть: >, <, або ==`);

        if (result === '==') {
            console.log(`10. Комп'ютер вгадав число: ${guess} за ${attempts} спроб!`);
            break;
        } else if (result === '>') {
            min = guess + 1;
        } else if (result === '<') {
            max = guess - 1;
        } else {
            console.log("10. Невірний ввід. Спробуйте ще раз.");
            attempts--;
            continue;
        }
    }
}