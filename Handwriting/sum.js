const assert = require("node:assert")
const { describe, it } = require("node:test")

function sum(...args) {
  function add(...argc) {
    args = [...args, ...argc]

    return add
  }

  add.valueOf = () => args.reduce((sum, num) => sum + num, 0)

  return add
}

/***** test *****/

describe('sum', () => {
  it('should sum function', () => {
    assert.strictEqual(sum(1, 2, 3, 4).valueOf(), 10)
    assert.strictEqual(sum(1, 2, 3)(4).valueOf(), 10)
    assert.strictEqual(sum(1, 2)(3)(4).valueOf(), 10)
    assert.strictEqual(sum(1)(2)(3)(4).valueOf(), 10)
  })
})
