/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
  let res = []
  arr.forEach((v, i) => {
      if (fn(v, i)) {
          res.push(v)
      }
  })
  return res
};
