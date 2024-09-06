const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on('line', function (line: string) {
  console.log(line.trim().split('').reverse().join(''));
});
