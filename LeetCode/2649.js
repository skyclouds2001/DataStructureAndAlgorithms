/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    for (const v of arr) {
        if (Array.isArray(v)) {
            yield* inorderTraversal(v)
        } else {
            yield v;
        }
    }
};
