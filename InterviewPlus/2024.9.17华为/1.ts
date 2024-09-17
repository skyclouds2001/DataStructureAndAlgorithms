const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

let products: number[]
let money: number

rl.on('line', function (line: string) {
  if (products == null) {
    products = line.trim().split(',').map(v => Number.parseInt(v))
  } else {
    money = Number.parseInt(line.trim())
    products.sort((a, b) => a - b).filter(v => v < money)

    if (products.length < 3) {
      console.log(-1)
      return
    }
    if (products[0] + products[1] + products[2] > money) {
      console.log(-1)
      return
    }

    // const flag = Array(products.length).fill(false)
    // let ans = -1
    // const find = (num: number, cost: number): void => {
    //   if (cost > money) {
    //     return
    //   }
    //   if (num === 3) {
    //     ans = ans > cost ? ans : cost
    //   }

    //   for (let i = 0; i < products.length; i++) {
    //     if (!flag[i]) {
    //       flag[i] = true
    //       find(num + 1, cost + products[i])
    //       flag[i] = false
    //     }
    //   }
    // }
    // find(0, 0)

    // console.log(ans)

    let res = -1
    const len = products.length
    for (let i = 0; i < len; ++i) {
        for (let j = 0; j < len; ++j) {
            for (let k = 0; k < len; ++k) {
                if (i != j && i != k && j != k) {
                    let total = products[i] + products[j] + products[k]
                    if (total <= money && total > res) {
                        res = total
                    }
                }
            }
        }
    }
    console.log(res)
  }
})
