const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const ip = data
  const parts = ip.split('.')

  if (parts.length !== 4) {
    console.log('NO')
    return
  }

  for (const part of parts) {
    if (part.startsWith('0') && part !== '0' || part.startsWith('+') || part.startsWith('-')) {
      console.log('NO')
      return
    }
    const num = Number.parseInt(part)
    if (Number.isNaN(num) || num < 0 || num > 255) {
      console.log('NO')
      return
    }
  }

  console.log('YES')
})
