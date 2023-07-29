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

/**
 * 现给定一个函数 fn，一个参数数组 args 和一个以毫秒为单位的超时时间 t ，返回一个取消函数 cancelFn 。
 *
 * 在经过 t 毫秒的延迟后，应该调用 fn 函数，并将 args 作为参数传递。除非 在 t 毫秒的延迟过程中，在 cancelT 毫秒时调用了 cancelFn。并且在这种情况下，fn 函数不应该被调用。
 *
 */
