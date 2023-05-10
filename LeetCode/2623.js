/**
 * @param {Function} fn
 */
function memoize(fn) {
    const map = new Map();

    return function(...args) {
        const key = args.join('-');
        if (map.has(key)) {
            return map.get(key);
        } else {
            const val = fn(...args);
            map.set(key, val);
            return val;
        }
    }
}
