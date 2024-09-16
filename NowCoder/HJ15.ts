const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line) {
  const num = Number.parseInt(line.trim())
  const res = num.toString(2)
  console.log(res.split('').reduce((pre, cur) => pre + (cur === '1' ? 1 : 0), 0))
});
