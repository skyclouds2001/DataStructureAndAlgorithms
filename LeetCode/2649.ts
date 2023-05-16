type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (const v of arr) {
        if (Array.isArray(v)) {
            yield* inorderTraversal(v)
        } else {
            yield v;
        }
    }
}
