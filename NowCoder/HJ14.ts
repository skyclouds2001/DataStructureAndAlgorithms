const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n: number
let cnt = 0
let strs: string[] = []

rl.on('line', function (data: string) {
  if (n == null) {
    n = Number.parseInt(data.trim())
  } else {
    ++cnt

    strs.push(data.trim())

    if (cnt === n) {
      strs.sort()

      strs.forEach((str) => {
        console.log(str)
      })
    }
  }
});
