/**
 * @param {Function[]} fns
 * @returns {Function}
 */
function compose(...fns) {
  return fns.reduce((res, it) => {
    return (...args) => {
      return res(it(...args))
    }
  }, (...args) => args)
}
