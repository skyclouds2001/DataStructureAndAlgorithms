/**
 * @param {any} thisArgs
 * @param {...any} args
 * @returns {any}
 */
function call(thisArgs, ...args) {
  if (!thisArgs) thisArgs = globalThis ?? window ?? global
  thisArgs = typeof thisArgs === 'object' && thisArgs !== null ? thisArgs : Object(thisArgs)

  const f = Symbol()

  Reflect.defineProperty(thisArgs, f, {
    value: this,
  })

  const res = thisArgs[f](...args)

  Reflect.deleteProperty(thisArgs, f)

  return res
}

let fn = function (name) {
  console.log(this, name)
}

Function.prototype.myCall = call

fn.myCall(null, 'test')
fn.myCall(true, 'test')
fn.myCall({ name: 'base' }, 'test')
