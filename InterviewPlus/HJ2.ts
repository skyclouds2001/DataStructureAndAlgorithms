const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let resource: string | null = null

rl.on('line', function (line) {
  if (resource == null) {
    resource = line.trim()
  } else {
    const target = line.trim()
    const uppercase = target.toUpperCase()
    const lowercase = target.toLowerCase()

    const count = resource.split('').reduce((acc, cur) => acc + (cur === uppercase || cur === lowercase ? 1 : 0), 0)
    console.log(count)
  }
});
