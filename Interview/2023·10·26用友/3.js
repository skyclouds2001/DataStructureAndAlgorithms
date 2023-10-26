/**
 * @param matrix {Array<Array<number>>}
 * @return {number}
 */
function shortestPath(matrix) {
  /**
   * @param x {number}
   * @param y {number}
   * @return {number}
   */
  function find(x, y) {
    if (x === row - 1 && y === column - 1) {
      return 0
    }

    if (x >= row || x < 0 || y >= column || y < 0) {
      return Number.MAX_VALUE
    }

    if (matrix[x][y] & 2) {
      return Number.MAX_VALUE
    }

    if (matrix[x][y] & 1) {
      return Number.MAX_VALUE
    }

    matrix[x][y] |= 2

    const paths = sets.map(set => find(x + set[0], y + set[1]))

    return Math.min(...paths) + 1
  }

  /**
   * @type {[x: number, y: number][]}
   */
  const sets = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ]

  const row = matrix.length
  const column = matrix.at(0).length

  const res = find(0, 0)

  return res !== Number.MAX_VALUE ? res : -1
}

module.exports = {
  shortestPath,
}
