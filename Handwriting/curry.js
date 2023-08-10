/**
 * @param {Function} func
 * @param {...any} args
 * @returns {Function}
 */
function curry(func, ...args) {
  return function(...params) {
    if (args.length + params.length < func.length) {
      return curry(func, ...args, ...params)
    } else {
      return func.call(this, ...args, ...params)
    }
  }
}

/***** test *****/

const assert = require("node:assert")
const { describe, it } = require("node:test")

describe('curry', () => {
  const sum = (num1, num2, num3) => num1 + num2 + num3

  it('should curry function', () => {
    assert.strictEqual(curry(sum)(1, 2, 3), 6)
    assert.strictEqual(curry(sum)(1, 2)(3), 6)
    assert.strictEqual(curry(sum)(1)(2)(3), 6)
    assert.strictEqual(curry(sum)(1)(2, 3), 6)
  })
})
