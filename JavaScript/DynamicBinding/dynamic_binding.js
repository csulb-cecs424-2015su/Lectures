var x = {firstName: "Neal", lastName: "Terrell"};
console.log();
console.log("Object's firstName property: " + x.firstName);
console.log("Object's favoriteSport property: " + x.favoriteSport);

x.favoriteSport = "Baseball";
console.log("Object's favoriteSport property: " + x.favoriteSport);

x.someFunction = function(p) {return p * p;};
console.log("Object's someFunction(10): " + x.someFunction(10));