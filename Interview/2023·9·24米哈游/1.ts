const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

let n: number
let a: number[]
let b: number[]

let step: 0 | 1 | 2 | 3 = 0

rl.on('line', function (line: string) {
    switch(step) {
      case 0:
        n = Number.parseInt(line.trim())
        break
      case 1:
        a = line.trim().split(' ').map((v) => Number.parseInt(v))
        break
      case 2:
        b = line.trim().split(' ').map((v) => Number.parseInt(v))

        const sa = a.reduce((pre, cur) => pre + cur, 0)
        const sb = b.reduce((pre, cur) => pre + cur, 0)

        const ans = Math.max(...a.map(v => (sa - v) ^ sb), ...b.map(v => sa ^ (sb - v)))

        console.log(ans)
    }

    ++step
})
