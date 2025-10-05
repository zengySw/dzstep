function task1(a, b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

console.log(`1. Менше з чисел (5, 12): ${task1(5, 12)}`);


function task2(base, exponent) {
    let result = 1;
    
    for (let i = 0; i < exponent; i++) {
        result *= base;
    }
    
    if (exponent === 0) {
        return 1;
    }
    
    return result;
}

console.log(`2. 3 в степені 4: ${task2(3, 4)}`);


function task3(num1, num2, operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 === 0) {
                return "Помилка: Ділення на нуль";
            }
            return num1 / num2;
        default:
            return "Помилка: Невірний оператор";
    }
}

console.log(`3. Приклад 10 * 4: ${task3(10, 4, '*')}`);
console.log(`3. Приклад 10 / 0: ${task3(10, 0, '/')}`);


function task4(number) {
    if (number <= 1) {
        return false;
    }
    
    for (let i = 2; i * i <= number; i++) {
        if (number % i === 0) {
            return false;
        }
    }
    
    return true;
}

console.log(`4. Число 17 просте? ${task4(17)}`);
console.log(`4. Число 18 просте? ${task4(18)}`);


function printMultiplicationTable(number) {
    console.log(`\nТаблиця множення для числа ${number}:`);
    for (let i = 1; i <= 10; i++) {
        console.log(`  ${number} * ${i} = ${number * i}`);
    }
}
function task5() {
    console.log("\n--- 5. Вивід таблиць множення від 2 до 9 ---");
    for (let n = 2; n <= 9; n++) {
        printMultiplicationTable(n);
    }
}


function task6(a, b) {
    if (b === 0) {
        return "Помилка: Ділення на нуль";
    }
    
    let quotient = Math.floor(a / b);
    
    let remainder = a - (quotient * b);
    
    return remainder;
}

console.log(`6. Остача від 17 / 5: ${task6(17, 5)}`);


function task7() {
    if (arguments.length === 0 || arguments.length > 5) {
        console.log("7. Помилка: функція приймає від 1 до 5 чисел.");
        return 0;
    }
    
    let sum = 0;
    
    for (let i = 0; i < arguments.length; i++) {
        if (typeof arguments[i] === 'number') {
            sum += arguments[i];
        }
    }
    
    return sum;
}

console.log(`7. Сума (1, 2, 3, 4): ${task7(1, 2, 3, 4)}`);



function task8() {
    if (arguments.length === 0 || arguments.length > 5) {
        console.log("8. Помилка: функція приймає від 1 до 5 чисел.");
        return undefined;
    }
    
    let max = arguments[0];
    
    for (let i = 1; i < arguments.length; i++) {
        if (arguments[i] > max) {
            max = arguments[i];
        }
    }
    
    return max;
}

console.log(`8. Більше з чисел (5, 8, 2, 9): ${task8(5, 8, 2, 9)}`);


function task9(start, end, isEven) {
    let output = [];
    
    console.log(`\n9. Вивід ${isEven ? 'парних' : 'непарних'} чисел у діапазоні від ${start} до ${end}:`);
    
    let current = start;
    
    for (let i = current; i <= end; i++) {
        if (isEven && i % 2 === 0) {
            output.push(i);
        } else if (!isEven && i % 2 !== 0) {
            output.push(i);
        }
    }
    
    console.log(`   Результат: ${output.join(', ')}`);
}

task9(10, 20, true);
task9(10, 20, false);


function isLeapYear(year) {
    return (year % 400 === 0) || (year % 4 === 0 && year % 100 !== 0);
}

function task10(day, month, year) {
    const daysInMonth = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }
    
    if (day < daysInMonth[month]) {
        day++;
    } else {
        day = 1;
        
        if (month === 12) {
            month = 1;
            year++;
        } else {
            month++;
        }
    }
    
    const d = String(day).padStart(2, '0');
    const m = String(month).padStart(2, '0');
    const y = String(year);
    
    return `${d}.${m}.${y}`;
}

console.log(`10. Наступний день після 15.03.2023: ${task10(15, 3, 2023)}`);
console.log(`10. Наступний день після 31.12.2023: ${task10(31, 12, 2023)}`);
console.log(`10. Наступний день після 28.02.2024 (високосний): ${task10(28, 2, 2024)}`);


