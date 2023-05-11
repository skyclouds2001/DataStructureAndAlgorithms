declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount !== this.length) return []

    const arr = Array<number[]>(rowsCount).fill(Array(colsCount).fill(0)).map(v => [...v])

    for (let i = 0; i < colsCount; ++i) {
        for (let j = 0; j < rowsCount; ++j) {
            arr[i % 2 === 0 ? j : rowsCount - j - 1][i] = this[i * rowsCount + j]
        }
    }

    return arr
}
