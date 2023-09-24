const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

let n: number, h: number
let t: number, x: number

let step = 0

let count = 0

let attack = 0

rl.on('line', function (line: string) {
    switch(step) {
      case 0:
        const arr = line.trim().split(' ').map(v => Number.parseInt(v))
        n = arr[0]
        h = arr[1]

        break

      default:
        const ar = line.trim().split(' ').map(v => Number.parseInt(v))
        t = ar[0]
        x = ar[1]

        switch(t) {
          case 1:
            count += x
            break
          case 2:
            h -= x
            attack += count
            count = 0
            break
        }

        if (n === step) {
          if (h <= 0) {
            console.log(1)
            return
          }

          if (h > attack * 6) {
            console.log(0)
            return
          }

          console.log(0.5)
        }

        break
    }

    ++step
})
