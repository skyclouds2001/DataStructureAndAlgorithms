/**
 * @param {any} target
 * @returns {boolean}
 */
const isObject = (target) => typeof target === 'object' && target !== null

/**
 * @param {object} obj
 * @param {Map<object, object>} cache
 * @returns {object}
 */
function deepClone(obj, cache = new Map()) {
  if (cache.has(obj)) {
    return cache.get(obj)
  }

  const target = Array.isArray(obj) ? [] : {}

  cache.set(obj, target)

  Reflect.ownKeys(obj).forEach((key) => {
    const val = obj[key]
    target[key] = isObject(val) ? deepClone(val, cache) : val
  })

  return target
}

const target = {
  field1: 1,
  field2: undefined,
  field3: {
      child: 'child'
  },
  field4: [2, 4, 8],
  f: { f: { f: { f: { f: { f: { f: { f: { f: { f: { f: { f: {} } } } } } } } } } } },
}

target.target = target

console.time()
console.log(deepClone(target))
console.timeEnd()
