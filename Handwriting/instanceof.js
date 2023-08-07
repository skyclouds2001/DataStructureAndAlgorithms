/**
 * @param {object} obj
 * @param {Function} func
 * @returns {boolean}
 */
function instanceOf(obj, func) {
  if ((typeof obj !== 'object' && typeof obj !== 'function') || obj === null) {
    return false
  }

  const proto = Object.getPrototypeOf(obj)

  return proto === func.prototype || instanceOf(proto, func)
}

/**
 * @param {object} obj
 * @param {Function} func
 * @returns {boolean}
 */
function instanceOfPlus(obj, func) {
  if ((typeof obj !== 'object' && typeof obj !== 'function') || obj === null) {
    return false
  }

  let proto = Object.getPrototypeOf(obj)
  while(true) {
    if (proto === null) {
      return false
    }
    if (proto === func.prototype) {
      return true
    }

    proto = Object.getPrototypeOf(obj)

    return proto === func.prototype || instanceOf(proto, func)
  }
}

let Fn = function () { }
let p1 = new Fn()

console.log(instanceOf({}, Object))
console.log(instanceOf(p1, Fn))
console.log(instanceOf({}, Fn))
console.log(instanceOf(null, Fn))
console.log(instanceOf(1, Fn))
console.log(instanceOf(function a() {}, Function))

console.log(instanceOfPlus({}, Object))
console.log(instanceOfPlus(p1, Fn))
console.log(instanceOfPlus({}, Fn))
console.log(instanceOfPlus(null, Fn))
console.log(instanceOfPlus(1, Fn))
console.log(instanceOfPlus(function a() {}, Function))
