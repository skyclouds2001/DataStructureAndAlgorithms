const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const str = data
  const map = new Map<string, number>()
  str.split('').forEach((ch) => {
    if (!map.has(ch)) {
      map.set(ch, 0)
    }
    map.set(ch, (map.get(ch) ?? 0) + 1)
  })
  const arr = Array.from(map).sort((a, b) => a[1] - b[1])
  let index = 0
  while (index + 1 < arr.length && arr[index][1] === arr[index + 1][1]) {
    ++index
  }
  const array = arr.slice(0, index + 1).map((v) => v[0])
  const res = str.split('').filter((v) => !array.includes(v)).join('')
  console.log(res)
})
