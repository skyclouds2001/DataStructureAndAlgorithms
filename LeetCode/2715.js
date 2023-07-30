/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    let id = setTimeout(() => {
        id = -1
        fn(...args)
    }, t)
    return function () {
        if (id > 0) {
            clearTimeout(id)
        }
    }
};
