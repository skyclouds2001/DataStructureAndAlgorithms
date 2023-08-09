/**
 * @param {Function} fn
 */
function memoize(fn) {
    const mv = new Map()
    const mi = new Map()
    let id = 0

    return function(...args) {
        const argc = args.reduce((pre, v) => {
            if (!mi.has(v)) {
                mi.set(v, id)
                ++id
            }
            return pre + '-' + mi.get(v)
        }, '')
        console.log(argc)

        if (!mv.has(argc)) {
            const res = fn(...args)
            mv.set(argc, res)
        }

        return mv.get(argc)
    }
}
