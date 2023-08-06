/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    context ||= window
    Reflect.defineProperty(context, 'fn', {
        enumerable: false,
        writable: false,
        value: this,
    })
    const res = context.fn(...args)
    delete context.fn
    return res
}
