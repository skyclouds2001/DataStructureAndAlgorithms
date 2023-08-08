/**
 * @param {object} obj
 * @param {PropertyDescriptorMap} properties
 * @returns {object}
 */
function create(obj, properties) {
  const C = function() {}

  C.prototype = obj

  const o = new C()

  if (properties) {
    Reflect.ownKeys(properties).forEach((key) => {
      Reflect.defineProperty(o, key, properties[key])
    })
  }

  if (obj === null) {
    Reflect.setPrototypeOf(o, null)
  }

  return o
}

const person = {
  showName () {
    console.log(this.name)
  }
}
const me = Object.create(person)
const me2 = create(person)

me.name = 'test'
me2.name = 'test'

me.showName()
me2.showName()

const emptyObj = Object.create(null)
const emptyObj2 = create(null)

console.log(emptyObj)
console.log(emptyObj2)

const props = {
  foo: {
    writable:true,
    configurable:true,
    value: "hello"
  },
  bar: {
    configurable: false,
    get: function() { return 10 },
    set: function(value) {
      console.log("Setting `o.bar` to", value);
    }
  }
}

let o = Object.create(Object.prototype, props)
let o2 = create(Object.prototype, props)

o.bar = 'test'
o2.bar = 'test'

console.log(o.foo)
console.log(o2.foo)
console.log(o.bar)
console.log(o2.bar)
