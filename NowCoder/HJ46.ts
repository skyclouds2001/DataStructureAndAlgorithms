const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let str: string | null = null

rl.on('line', function (line: string) {
  if (str === null) {
    str = line.trim()
  } else {
    const cnt = Number.parseInt(line.trim())
    console.log(str.split('').slice(0, cnt).join(''))
  }
});
