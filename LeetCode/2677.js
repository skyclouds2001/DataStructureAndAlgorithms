/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
  return Array(Math.ceil(arr.length / size)).fill(0).map((_, i) => Array(size).fill(0).map((_, j) => ((i * size + j) < arr.length) ? arr[i * size + j] : Number.NaN).filter(v => !Number.isNaN(v)));
};
