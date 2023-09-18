/**
 * IP地址解析
 * @param {string} str string字符串 待解析IP地址
 * @return {string[]} string字符串一维数组
 */
function restore_ip_address(str) {
  const ips = new Set()
  const len = str.length

  const find = (ip, v, index) => {
    if (index >= len && Number.isNaN(v)) {
      ips.add(Array.from(ip).join('.'))
    }

    if (ip.length >= 4) {
      return
    }

    const _n = Number.parseInt(str[index])
    const _v = v * 10 + _n

    if (_v >= 0 && _v <= 255) {
      find(Array.from(ip), _v, index + 1)
      find(Array.of(...ip, v), _n, index + 1)
    } else {
      find(Array.of(...ip, v), _n, index + 1)
    }
  }

  find(Array.from([]), Number.parseInt(str[0]), 1)

  return Array.from(ips)
}

module.exports = {
  restore_ip_address,
}
