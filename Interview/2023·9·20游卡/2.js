/**
 * @param {any[]} arr int整型一维数组 
 * @return {any[]} int整型一维数组
 */
function filterMap(arr) {
  /**
   * @param {any} a 
   * @param {any} b 
   */
  function is(a, b) {
    let flag = false

    if (typeof a !== typeof b) { // are not same basic type
      flag = false
    } else if (typeof a !== 'object' || a == null) { // are both same basic type except for object
      flag = Object.is(a, b)
    } else { // are both object type
      if (Array.isArray(a) && Array.isArray(b)) { // all are array
        flag = a.every((v, i) => is(v, b[i]))
      } else if (Array.isArray(a) || Array.isArray(b)) { // one is array
        flag = false
      } else { // none is array
        flag = Object.entries(a).every(([k, v]) => is(v, b[k]))
      }
    }

    return flag
  }

  const array = []

  let f = false
  for (let i = 0; i < arr.length; ++i) {
    f = false

    for (let j = i + 1; j < arr.length; ++j) {
      f ||= is(arr[i], arr[j])
    }

    if (!f) {
      array.push(arr[i])
    }
  }

  return array
}

module.exports = {
  filterMap,
}
