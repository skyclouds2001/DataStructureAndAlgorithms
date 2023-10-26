/**
 * @param level {number} 嵌套层级
 * @param count {number} 每层的元素数
 * @return {string}
 */
function generateNestedArray(level, count) {
  /**
   * @param level {number} 嵌套层级
   * @param count {number} 每层的元素数
   * @return {number[]}
   */
  function flat(level, count) {
      return level === 1 ?
          Array(count).fill('youyou') :
          Array(count).fill(0).map(() => flat(level - 1, count))
  }

  return JSON.stringify(flat(level, count)).replace(/"/g, "'")
}

module.exports = {
  generateNestedArray,
}
