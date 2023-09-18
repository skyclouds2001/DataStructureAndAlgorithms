/**
 * 找到数组中重复数字
 * @param {number[]} nums int整型一维数组 数组
 * @return {number[]} int整型一维数组
 */
function findDuplicates(nums) {
  const set = new Set()
  const ans = new Set()

  for (const v of nums) {
    if (set.has(v)) {
      ans.add(v)
    } else {
      set.add(v)
    }
  }

  return Array.from(ans).sort((a, b) => a - b)
}

module.exports = {
  findDuplicates,
}
