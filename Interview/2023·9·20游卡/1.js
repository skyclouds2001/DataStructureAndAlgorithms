/**
 * @param {any[]} arr 搜索的数组
 * @param {any} target 搜索的对象
 * @param {number} start start=0
 * @return {number}
 */
function indexOf(arr, target, start = 0) {
  let id = -1

  for (let i = start; i < arr.length; ++i) {
    if (arr[i] === target) {
      id = i
      break
    }
  }

  return id
}

module.exports = {
  indexOf,
}
