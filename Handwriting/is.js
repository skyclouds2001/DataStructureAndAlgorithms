function is(x, y) {
  return x === y ? x !== 0 || 1 / x === 1 / y : x !== x && y !== y
}

/***** test *****/

const assert = require("node:assert")
const { describe, it } = require("node:test")

describe('is', () => {
  it('should behave like Object.is() is', () => {
    assert.strictEqual(is(NaN, NaN), true)
    assert.strictEqual(is(0, 0), true)
    assert.strictEqual(is(1, 1), true)
    assert.strictEqual(is(Infinity, Infinity), true)
    assert.strictEqual(is(+0, -0), false)
    assert.strictEqual(is(2, 4), false)
    assert.strictEqual(is(NaN, 4), false)
    assert.strictEqual(is(Infinity, NaN), false)
    assert.strictEqual(is(Infinity, 7), false)

    assert.strictEqual(is(true, true), true)
    assert.strictEqual(is(false, false), true)
    assert.strictEqual(is(true, false), false)

    assert.strictEqual(is('', ''), true)
    assert.strictEqual(is('dr', 'dr'), true)
    assert.strictEqual(is('', 'r1'), false)

    assert.strictEqual(is(null, null), true)
    assert.strictEqual(is(undefined, undefined), true)
    assert.strictEqual(is(null, undefined), false)

    assert.strictEqual(is(Symbol('a'), Symbol('a')), false)

    assert.strictEqual(is(121n, 121n), true)
    assert.strictEqual(is(121n, 143n), false)

    assert.strictEqual(is(/12/, /12/), false)
    assert.strictEqual(is([], []), false)
    assert.strictEqual(is({}, {}), false)
  })
})
