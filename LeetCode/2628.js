/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
  const isObj = (o) => typeof o === 'object' && o !== null;

  const checkObj = (o1, o2) => isObj(o1) && isObj(o2) && Array.isArray(o1) === Array.isArray(o2) && Object.keys(o1).length === Object.keys(o2).length && Object.keys(o1).every((k) => o1[k] === o2[k] || checkObj(o1[k], o2[k]))

  return o1 === o2 || checkObj(o1, o2);
};
