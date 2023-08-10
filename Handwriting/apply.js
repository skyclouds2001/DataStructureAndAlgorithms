/**
 * @param {any} thisArgs
 * @param {any[]} args
 * @returns {any}
 */
function apply(thisArgs, args = []) {
  if (thisArgs == null) thisArgs = globalThis ?? window ?? global
  thisArgs = typeof thisArgs === 'object' && thisArgs !== null ? thisArgs : Object(thisArgs)

  const f = Symbol()

  Reflect.defineProperty(thisArgs, f, {
    value: this,
  })

  const res = thisArgs[f](...args)

  Reflect.deleteProperty(thisArgs, f)

  return res
}

/***** test *****/

const assert = require("assert")
const { describe, before, after, it } = require("node:test")

describe('apply', () => {
  const GLOBAL_NAME = 'global name'
  const OBJECT_NAME = 'object name'
  const f = function(name) {
    return name
  }
  const fn = function () {
    return this.name
  }

  before(() => {
    Function.prototype.myApply = apply
    globalThis.name = GLOBAL_NAME
  })

  after(() => {
    delete Function.prototype.myApply
    delete globalThis.name
  })

  it('should apply with globalThis without params', () => {
    const name = fn.myApply()
    assert.strictEqual(name, GLOBAL_NAME)
  })

  it('should apply with given object param', () => {
    const name = fn.myApply({ name: OBJECT_NAME })
    assert.strictEqual(name, OBJECT_NAME)
  })

  it('should apply with wrap class with null or undefined value param', () => {
    const name1 = fn.myApply(null)
    assert.strictEqual(name1, GLOBAL_NAME)
    const name2 = fn.myApply(undefined)
    assert.strictEqual(name2, GLOBAL_NAME)
  })

  it('should apply with wrap class with primitive value param', () => {
    const name1 = fn.myApply(1)
    assert.strictEqual(name1, undefined)
    const name2 = fn.myApply('str')
    assert.strictEqual(name2, undefined)
    const name3 = fn.myApply(true)
    assert.strictEqual(name3, undefined)
    const name4 = fn.myApply(Symbol('sym'))
    assert.strictEqual(name4, undefined)
    const name5 = fn.myApply(1345432n)
    assert.strictEqual(name5, undefined)
  })

  it('should apply with function param', () => {
    const name = f.myApply({}, [OBJECT_NAME])
    assert.strictEqual(name, OBJECT_NAME)
  })
})
