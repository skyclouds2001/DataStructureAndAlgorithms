/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
  let res = [];
  arr.forEach((v, i) => {
      res.push(fn(v, i));
  });
  return res;
};
