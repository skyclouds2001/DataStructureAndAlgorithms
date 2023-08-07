/**
 * @param {any[]} arr
 * @returns {any[]}
 */
function flat(arr) {
  return arr.reduce((arr, it) => {
    return arr.concat(Array.isArray(it) ? flat(it) : it)
  }, [])
}

console.log(flat([1, 2, 3, [4, 5, [6, 7, 8, [9]]]]))
