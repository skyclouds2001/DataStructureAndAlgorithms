const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const money = exec(data.trim())

  console.log(money)
})

const mp = ['零', '壹', '贰', '叁', '肆', '伍', '陆', '柒', '捌', '玖']

function exec(money: string): string {
  const [integer, double] = money.split('.')
  return '人民币' + exec_integer(integer) + exec_double(double)
}

function exec_double(money: string): string {
  let res: string
  if (money == null) {
    money = ''
  }
  while (money.length < 2) {
    money += '0'
  }

  if (money[0] === '0' && money[1] === '0') {
    res = '整'
  } else if (money[1] === '0') {
    res = `${mp[money[0]]}角`
  } else if (money[0] === '0') {
    res = `${mp[money[1]]}分`
  } else {
    res = `${mp[money[0]]}角${mp[money[1]]}分`
  }

  return res
}

function exec_integer(money: string): string {
  if (money === '0') {
    return ''
  }

  let res = ''

  if (money.length > 4) {
    res += exec_integer_base(money, 1)
  }

  res += exec_integer_base(money, 0)

  return res
}

function exec_integer_base(money: string, depth: number): string {
  const begin = (depth + 1) * (-4)
  const end = depth * (-4)
  let mon = depth !== 0 ? money.slice(begin, end) : money.slice(begin)
  let res: string[] = []

  while (mon.length < 4) {
    mon = '0' + mon
  }

  if (mon[0] !== '0') {
    res.push(mp[Number.parseInt(mon[0])] + '仟')
  } else {
    res.push(mp[Number.parseInt(mon[0])])
  }

  if (mon[1] !== '0') {
    res.push(mp[Number.parseInt(mon[1])] + '佰')
  } else {
    res[res.length - 1] !== '零' && res.push(mp[Number.parseInt(mon[1])])
  }

  if (mon[2] !== '0' && mon[2] != '1') {
    res.push(mp[Number.parseInt(mon[2])] + '拾')
  } else {
    if (mon[2] === '0') {
      res[res.length - 1] !== '零' && res.push(mp[Number.parseInt(mon[2])])
    }
    if (mon[2] === '1') {
      res.push('拾')
    }
  }

  if (mon[3] !== '0') {
    res.push(mp[Number.parseInt(mon[3])])
  }

  while ((money.length < 4 || money.slice(begin, end).length < 4) && res[0] === '零') {
    res.shift()
  }

  while (res.length > 0 && res[res.length - 1] === '零') {
    res.pop()
  }

  switch (depth) {
    case 0:
      res.push('元')
      break
    case 1:
      res.push('万')
      break
  }

  return res.join('')
}
