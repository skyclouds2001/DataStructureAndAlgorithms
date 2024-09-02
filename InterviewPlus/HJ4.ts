const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (data: string) {
  const str = data.trim()
  const len = str.length

  let t = 0
  while (len - t >= 8) {
    console.log(str.slice(t, t + 8))
    t += 8
  }

  if (t === len) return
  let res = str.slice(t)
  while (res.length < 8) {
    res += '0'
  }
  console.log(res)
});
