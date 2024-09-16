const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

let step = 0

rl.on('line', function (data: string) {
  switch (step) {
    case 0:
        const ns = data.trim().split('.').map(v => Number.parseInt(v))
        console.log(ns[0] * (256 ** 3) + ns[1] * (256 ** 2) + ns[2] * (256 ** 1) + ns[3] * (256 ** 0))
        break
    case 1:
        const num = Number.parseInt(data.trim())
        console.log([Math.floor(num / 256 / 256 / 256) % 256, Math.floor(num / 256 / 256) % 256, Math.floor(num / 256) % 256, num % 256].join('.'))
        break
  }
  ++step
})
