/**
 * @param {Function} func
 * @param  {...any} args
 * @returns {object}
 */
function newObject(func, ...args) {
  const New = function () {}
  New.prototype = func.prototype
  New.prototype.constructor = func
  const obj = new New()
  // const obj = Object.create(func.prototype)

  const res = func.call(obj, ...args)
  // const ans = func.apply(obj, args)

  return typeof res === 'object' && res !== null || typeof res === 'function' ? res : obj
}

let Person = function (name) {
  this.name = name
}

Person.prototype.show = function () {
  console.log(this)
  console.log(this.name)
}

let p = newObject(Person, 'test')

console.log(p)
