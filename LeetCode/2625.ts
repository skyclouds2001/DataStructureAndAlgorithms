type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if (n <= 0) return arr

    const array = Array<MultiDimensionalArray | number>()

    arr.forEach((v) => {
        if (Array.isArray(v)) {
            array.push(...flat(v, n - 1))
        } else {
            array.push(v)
        }
    })

    return array
}
