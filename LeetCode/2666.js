/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
  let flag = false;
  return function(...args){
      if (!flag) {
          flag = true;
          return fn(...args);
      }
  };
};
