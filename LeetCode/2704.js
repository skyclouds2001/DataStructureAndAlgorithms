/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: (v) => {
            if (v !== val) {
                throw 'Not Equal'
            }
            return true
        },
        notToBe: (v) => {
            if (v === val) {
                throw 'Equal'
            }
            return true
        },
    }
}
