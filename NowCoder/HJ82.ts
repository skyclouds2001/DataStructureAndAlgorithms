const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const [f, s] = data.trim().split("/").map(v => Number.parseInt(v))

  let a = f, b = s
  const list = [] as number[]

  while (b % a != 0) {
    const c = Math.floor(b / a) + 1
    list.push(c)
    a = a * c - b
    b = b * c
  }

  list.push(b / a)

  console.log(list.map(v => `1/${v}`).join('+'))
})
