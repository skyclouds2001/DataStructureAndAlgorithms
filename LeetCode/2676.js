/**
 * @param fn {Function}
 * @param t {number}
 * @returns {Function}
 */
var throttle = function (fn, t) {
    let flag = false
    let arg = null

    const handle = () => {
        if (arg) {
            fn(...arg)
            arg = null
            setTimeout(handle, t)
        } else {
            flag = false
        }
    }

    return function (...args) {
        if (!flag) {
            fn(...args)
            flag = true
            setTimeout(handle, t)
        } else {
            arg = args
        }
    }
};
