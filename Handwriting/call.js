/**
 * @param {any} thisArgs
 * @param {...any} args
 * @returns {any}
 */
function call(thisArgs, ...args) {
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

describe('call', () => {
  const GLOBAL_NAME = 'global name'
  const OBJECT_NAME = 'object name'
  const f = function(name) {
    return name
  }
  const fn = function () {
    return this.name
  }

  before(() => {
    Function.prototype.myCall = call
    globalThis.name = GLOBAL_NAME
  })

  after(() => {
    delete Function.prototype.myCall
    delete globalThis.name
  })

  it('should call with globalThis without params', () => {
    const name = fn.myCall()
    assert.strictEqual(name, GLOBAL_NAME)
  })

  it('should call with given object param', () => {
    const name = fn.myCall({ name: OBJECT_NAME })
    assert.strictEqual(name, OBJECT_NAME)
  })

  it('should call with wrap class with null or undefined value param', () => {
    const name1 = fn.myCall(null)
    assert.strictEqual(name1, GLOBAL_NAME)
    const name2 = fn.myCall(undefined)
    assert.strictEqual(name2, GLOBAL_NAME)
  })

  it('should call with wrap class with primitive value param', () => {
    const name1 = fn.myCall(1)
    assert.strictEqual(name1, undefined)
    const name2 = fn.myCall('str')
    assert.strictEqual(name2, undefined)
    const name3 = fn.myCall(true)
    assert.strictEqual(name3, undefined)
    const name4 = fn.myCall(Symbol('sym'))
    assert.strictEqual(name4, undefined)
    const name5 = fn.myCall(1345432n)
    assert.strictEqual(name5, undefined)
  })

  it('should call with function param', () => {
    const name = f.myCall({}, OBJECT_NAME)
    assert.strictEqual(name, OBJECT_NAME)
  })
})
