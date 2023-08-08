/**
 * @param {object} obj
 * @returns {boolean}
 */
function isCyclic(obj) {
  const set = new Set()
  let isCyclic = false

  /**
   * @param {object} obj
   * @returns {boolean}
   */
  const detect = (obj) => {
    if (set.has(obj)) {
      isCyclic = true
      return
    }

    set.add(obj)

    Reflect.ownKeys(obj).forEach(key => {
      const val = obj[key]
      if (typeof val === 'object' && val !== null) {
        detect(val)
      }
    })

    set.delete(obj)
  }

  detect(obj)

  return isCyclic
}

let obj1 = { name: '前端胖头鱼1' }
let obj2 = { name: '前端胖头鱼2' }
obj1.obj = obj2
obj2.obj = obj1

let obj = { name: '前端胖头鱼1' }
obj.child = obj

let obj3 = {
  name: '前端胖头鱼',
  child: {}
}

obj3.child.obj = obj3.child

let tempObj = {
  name: '前端胖头鱼'
}
let obj4 = {
  obj1: tempObj,
  obj2: tempObj,
}

console.log(isCyclic(obj1))
console.log(isCyclic(obj2))
console.log(isCyclic(obj))
console.log(isCyclic(obj3))
console.log(isCyclic(obj4))
