// 一组整数，删除其中一个数，使其乘积最大，返回乘积最大值

function execute(data) {
  if (data.length === 0) {
    return 0
  }

  const po = data.filter(v => v > 0)
  const zo = data.filter(v => v === 0)
  const ng = data.filter(v => v < 0)

  if (zo.length > 1) {
    return 0
  }
  if (zo.length === 1) {
    if (ng.length % 2 === 0) {
      // remove 0
      return data.reduce((total, cur) => cur !== 0 ? total * cur : total)
    } else {
      // keep 0
      return 0
    }
  }

  let num
  let result = data.reduce((total, cur) => total * cur)

  if (ng.length % 2 === 0) {
    if (po.length > 0) {
      num = Math.min(...po)
    } else {
      num = Math.min(...ng)
    }
  } else {
    num = Math.max(...ng)
  }

  return result / num
}

console.log(execute([1, 5, 4, 2, 3]))
console.log(execute([1, 5, 4, 2, 0]))
console.log(execute([1, 5, 0, 0, 0]))
console.log(execute([1, 5, 4, 2, -3]))
console.log(execute([1, 5, 4, -2, -3]))
console.log(execute([1, 5, -4, -2, -3]))
console.log(execute([-5, -4, -2, -3]))
console.log(execute([-1, -5, -4, -2, -3]))
