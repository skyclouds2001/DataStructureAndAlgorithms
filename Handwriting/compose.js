/**
 * @param {Function[]} fns
 * @returns {Function}
 */
function compose(...fns) {
  return fns.reduce((res, it) => {
    return (...args) => {
      return res(it(...args))
    }
  }, (args) => args)
}

console.log(compose(v => v + 1, v => v + 2, v => v + 3, v => v + 4)(5))
