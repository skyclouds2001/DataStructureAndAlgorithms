const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line: string) {
  const str = line.trim();

  console.log(str.split(' ').reverse().join(' '))
});
