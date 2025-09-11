let name = prompt("enter name", "john");
alert(`hello, ${name}`);

const year = 2025;
let age = prompt("enter birth year", "2000");
alert(`your age: ${year-age}`);

let square = prompt("enter square line", "10");
alert(`${parseInt(square)*2}`);

const Pi = 3.14;
let circle = prompt("enter radius", 10);
alert(`square or circle: ${(Pi*parseInt(circle))*(Pi*parseInt(circle))}`);

let km = prompt("enter distance in km", 10);
let speed = prompt("enter speed km/h", 12);
alert(`you will arrive in the city: ${km/speed}h`);

const EuroDollar = 1.14;
let dollars = prompt("enter dollars for convert into euros", 100);
alert(`${parseFloat(dollars)/EuroDollar}`);

const sizeMB = 820;
let count;
let flashGB = prompt("enter size of your flash, in GB", 1024);
let convertGBtoMB = parseInt(flashGB) * 1024;
for (let sizetemp = sizeMB; convertGBtoMB > sizetemp; count++) {
    sizetemp += sizetemp*2;
}
alert(`${count} times u can save files with size 820mb in ${flashGB}gb`);
