let a = parseInt(prompt("enter num", 2));
let countA = 0;
while (a >= countA) {
    document.writeln("#");
    countA++;
}

let countB = 0;
let b = prompt("enter num", 2);
while (parseInt(b) >= countB) {
    document.writeln(countB);
    countB++;
}

let c = parseInt(prompt("enter Power", 2));
let c1 = 0;
c1 = parseInt(prompt("enter num", 2));
let countC = 1;
let equals = 0;
while (c > countC) {
    countC++;
    equals += c1 * c1;
}
console.log(equals);

let d = parseInt(prompt("enter num", 4));
let countD = 0;
let equalsA = 1;
while (d > countD)
{
    equalsA += equalsA * countD
    countD++;
}
console.log(equalsA);

