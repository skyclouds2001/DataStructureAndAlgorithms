/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
  const result = new Array(functions.length)
  let count = 0
  return new Promise((resolve, reject) => {
    functions.forEach((fn, index) => {
      fn().then((value) => {
        result[index] = value
        ++count
        if (count === functions.length) {
          resolve(result)
        }
      }, (reason) => {
        reject(reason)
      })
    })
  })
}
