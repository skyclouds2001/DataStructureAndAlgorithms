/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, depth) {
    if (depth <= 0) return arr

    const array = []

    arr.forEach((v) => {
        if (Array.isArray(v)) {
            array.push(...flat(v, depth - 1))
        } else {
            array.push(v)
        }
    })

    return array
}
