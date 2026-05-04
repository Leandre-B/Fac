function Dalton(prenom){
    this.prenom=prenom;
}

Dalton.prototype.log = function(){
    console.log(this.prenom);
};

//AVERELL
let averell = new Dalton("Averell");
//averell.log();

//JACK
let jack = Object.create(Dalton.prototype);
jack.prenom="Jack";
//jack.log();

//JOE
let joe= {
    prenom : "Joe"
};

joe.__proto__ = new Dalton;
//joe.log();

//WILLIAM
let json='{ "prenom" : "William" }';
let william = JSON.parse(json);
william.__proto__ = new Dalton;
//william.log();


// console.log(Object.getPrototypeOf(averell)          === Dalton.prototype);
// console.log(Object.getPrototypeOf(jack)             === Dalton.prototype);
// console.log(Object.getPrototypeOf(joe.__proto__)    === Dalton.prototype);
// console.log(Object.getPrototypeOf(william.__proto__)=== Dalton.prototype);

// console.log(william.hasOwnProperty());
// console.log(Object.getOwnPropertyNames(william));
// console.log(Object.keys(william));

// for( prop in william){
//     console.log(prop);
// }