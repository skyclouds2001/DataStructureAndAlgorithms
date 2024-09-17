const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

let N: number, M: number
let partners: Array<{ scores: number[], total: number, id: number }>
let t = 0

rl.on('line', function (line: string) {
  if (t === 0) {
    const nums = line.trim().split(',')
    M = Number.parseInt(nums[0])
    N = Number.parseInt(nums[1])
    partners = Array(N).fill(0).map((_, i) => ({
        scores: Array(M).fill(0),
        total: 0,
        id: i + 1,
    }))
  } else if (t <= M) {
    const scores = line.trim().split(',').map(v => Number.parseInt(v))
    scores.forEach((score, i) => {
      partners[i].scores[t - 1] = score
      partners[i].total += score
    })
  }
  ++t
})

rl.on('close', function () {
  if (M < 3 || M > 10 ||
      N < 3 || N > 100 ||
      partners.some(v => v.scores.some(vv => vv < 1 || vv > 10))
  ) {
    console.log(-1)
    return
  }

  function count(array: number[], value: number) {
    return array.filter(v => v === value).length
  }

  partners.sort(
    (a, b) => {
      if (a.total < b.total) {
        return 1
      }
      if (a.total === b.total) {
        for (let k = 10; k >= 1; --k) {
          if (count(a.scores, k) < count(b.scores, k)) {
            return 1
          }
        }
      }
      return -1
    }
  )

  partners.sort(
    (a, b) => {
      if (a.total < b.total) {
        return 1
      }
      if (a.total === b.total) {
        for (let k = 10; k >= 1; --k) {
          if (count(a.scores, k) < count(b.scores, k)) {
            return 1
          }
          if (count(a.scores, k) > count(b.scores, k)) {
            return -1
          }
        }
      }
      return -1
    }
  )

  console.log(partners.slice(0, 3).map(partner => partner.id).join(','))
})
