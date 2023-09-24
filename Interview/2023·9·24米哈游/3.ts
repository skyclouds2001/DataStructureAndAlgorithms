const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

let step = false

let n: number
let a: number[]

const MOD = 1000000000 + 7

rl.on('line', function (line: string) {
    switch (step) {
      case false:
        n = Number.parseInt(line.trim())

        break
      case true:
        a = line.trim().split(' ').map((v) => Number.parseInt(v))

        // let sum = 0
        // let total = 0
        // for (let i = 0; i < n; ++i) {
        //   sum += a[i]

        //   for (let j = i + 1; j < n; ++j) {
        //     total += a[i] * a[j]
        //   }
        // }

        let ans = 0

        // for (let i = 0; i < n; ++i) {
        //   for (let j = i + 1; j < n; ++j) {
        //     ans += (j - i) * a[i] * a[j] % MOD
        //   }
        // }

        for (let step = 1; step < n; ++step) {
          let count = 0
          let val = a[0]

          for (let index = step; index < n - step; index += step) {
            val *= a[index]

            count += val

            val /= a[index - step]
          }

          ans += step * count % MOD
        }
        
        // for (let i = 0; i < n; ++i) {
        //   for (let j = 1; j < n; ++j) {
        //     ans += j * a[i] * a[i + j] % MOD
        //   }
        // }
        // for (let j = 1; j <= n; ++j) {
        //   let s = sum - a[n - j]
        //   let t = total - (sum - a[n - j])* a[n - j]
        // }

        console.log(ans)

        break
    }

    step = !step
})
