/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return []

    const arr = Array(rowsCount).fill(Array(colsCount).fill(0)).map(v => [...v])

    for (let i = 0; i < colsCount; ++i) {
        for (let j = 0; j < rowsCount; ++j) {
            arr[i % 2 === 0 ? j : rowsCount - j - 1][i] = this[i * rowsCount + j]
        }
    }

    return arr
}
