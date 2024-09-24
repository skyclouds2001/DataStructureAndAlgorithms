const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data) {
  const cards = data.trim().split(' ')

  if (cards.some(card => card === 'joker' || card === 'JOKER')) {
    console.log('ERROR')
    return
  }

  const vals = cards.map(card => CARD[card])
  const visited = Array(4).fill(false)
  const datas = []
  const syms = []

  for (let a = 0; a < 4; ++a) {
    if (visited[a]) {
      continue
    }
    visited[a] = true
    datas.push(vals[a])

    for (let b = 0; b < 4; ++b) {
      if (visited[b]) {
        continue
      }
      visited[b] = true
      datas.push(vals[b])

      for (let c = 0; c < 4; ++c) {
        if (visited[c]) {
          continue
        }
        visited[c] = true
        datas.push(vals[c])

        for (let d = 0; d < 4; ++d) {
          if (visited[d]) {
            continue
          }
          visited[d] = true
          datas.push(vals[d])

          for (let x = 0; x < 4; ++x) {
            syms.push(x)

            for (let y = 0; y < 4; ++y) {
              syms.push(y)

              for (let z = 0; z < 4; ++z) {
                syms.push(z)

                let res = datas[0], p = 0
                while (p < 3) {
                  switch (syms[p]) {
                    case 0:
                      res = res + datas[p + 1]
                      break
                    case 1:
                      res = res - datas[p + 1]
                      break
                    case 2:
                      res = res * datas[p + 1]
                      break
                    case 3:
                      res = Math.floor(res / datas[p + 1])
                      break
                  }
                  ++p
                }
                if (res === 24) {
                  console.log([RCARD[datas[0]], RSYM[syms[0]], RCARD[datas[1]], RSYM[syms[1]], RCARD[datas[2]], RSYM[syms[2]], RCARD[datas[3]]].join(''))
                  return
                }

                syms.pop()
              }

              syms.pop()
            }

            syms.pop()
          }

          visited[d] = false
          datas.pop()
        }

        visited[c] = false
        datas.pop()
      }

      visited[b] = false
      datas.pop()
    }

    visited[a] = false
    datas.pop()
  }

  console.log('NONE')
  return
})

const CARD = {
  '3': 3,
  '4': 4,
  '5': 5,
  '6': 6,
  '7': 7,
  '8': 8,
  '9': 9,
  '10': 10,
  J: 11,
  Q: 12,
  K: 13,
  A: 1,
  '2': 2,
}

const RCARD = Object.fromEntries(Object.entries(CARD).map(([k, v]) => ([v, k])))

const SYM = {
  '+': 0,
  '-': 1,
  '*': 2,
  '/': 3,
}

const RSYM = Object.fromEntries(Object.entries(SYM).map(([k, v]) => ([v, k])))
