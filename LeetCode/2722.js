/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
  const target = []

  Object.values(arr1).forEach((value) => {
    target[value.id] = value
  })

  Object.values(arr2).forEach((value) => {
    if (value.id in target) {
      target[value.id] = { ...target[value.id], ...value }
    } else {
      target[value.id] = value
    }
  })

  return target.filter(v => v)
}
