/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
  return function curried(...args) {
      return args.length === fn.length ? fn(...args) : (...argv) => curried(...args, ...argv);
  };
};
