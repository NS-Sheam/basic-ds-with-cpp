const sleep = (ms) => new Promise((resolve) => setTimeout(resolve, ms));

async function demo() {
  console.log("Hello");
  await sleep(1000);
  console.log("Hi");
}

// demo();
// -----------------
console.log("1");

setTimeout(() => console.log("2"), 0);

Promise.resolve().then(() => console.log("3"));

console.log("4");

// ----------------

async function foo() {
  console.log("X");
  return "Y";
}

foo().then((res) => console.log(res));

console.log("Z");
// ------------------
(async () => {
  console.log(1);
  await Promise.resolve();
  console.log(2);
})();

console.log(3);

await Promise.resolve();
console.log(4);
// --------------------
console.log(team);
var team = "Hi";
function team() {
  return "Hello";
}

// ---------------------

// Input:  [1, 2, 2, 3, 4, 4, 5]
// Output: [1, 2, 3, 4, 5]
