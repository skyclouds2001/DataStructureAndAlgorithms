/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let id = null

    return function (...args) {
        if (id) {
            clearTimeout(id)
            id = null
        }
        id = setTimeout(fn, t, ...args)
    };
}
