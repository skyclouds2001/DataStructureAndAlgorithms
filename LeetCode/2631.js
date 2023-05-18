/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
  const ans = {};
  for (let i = 0; i < this.length; ++i) {
      const v = this[i];
      const k = fn(v);
      if (ans[k]) {
          ans[k].push(v);
      } else {
          ans[k] = [v]
      }
  }
  return ans;
};
