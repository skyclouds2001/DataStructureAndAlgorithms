/**
 * @param {any} thisArgs
 * @param {any[]} args
 * @returns {any}
 */
function apply(thisArgs, args) {
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

Function.prototype.myApply = apply

fn.myApply(null, ['test'])
fn.myApply(true, ['test'])
fn.myApply({ name: 'base' }, ['test'])
