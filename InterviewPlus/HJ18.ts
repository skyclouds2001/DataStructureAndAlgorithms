const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const [ip, mask] = data.trim().split('~')
  const ips = ip.split('.').filter(v => v).map(v => Number.parseInt(v))
  const masks = mask.split('.').filter(v => v).map(v => Number.parseInt(v))

  if (ips[0] == 0 || ips[0] == 127) {
    return
  }

  if (
    ips.length != 4 ||
    masks.length != 4 ||
    ips.some(v => Number.isNaN(v) || v < 0 || v > 255) ||
    masks.some(v => Number.isNaN(v) || v < 0 || v > 255) ||
    masks.every(v => v === 0) ||
    masks.every(v => v === 255) ||
    (~(masks.reduce((ttl, val) => ttl * 256 + val, 0)) + 1) & (~(masks.reduce((ttl, val) => ttl * 256 + val, 0)))
  ) {
    ++cnt_invalid
    return
  }

  if (
    ips[0] == 10 ||
    ips[0] == 172 && ips[1] >= 16 && ips[1] <= 31 ||
    ips[0] == 192 && ips[1] == 168
  ) {
    ++cnt_secure
  }

  switch (true) {
    case (ips[0] >= 1 && ips[0] <= 126):
      ++cnt_a
      break
    case (ips[0] >= 128 && ips[0] <= 191):
      ++cnt_b
      break
    case (ips[0] >= 192 && ips[0] <= 223):
      ++cnt_c
      break
    case (ips[0] >= 224 && ips[0] <= 239):
      ++cnt_d
      break
    case (ips[0] >= 240 && ips[0] <= 255):
      ++cnt_e
      break
  }
})

rl.on('close', function () {
  console.log(cnt_a, cnt_b, cnt_c, cnt_d, cnt_e, cnt_invalid, cnt_secure)
})

let cnt_a = 0, cnt_b = 0, cnt_c = 0, cnt_d = 0, cnt_e = 0, cnt_invalid = 0, cnt_secure = 0
