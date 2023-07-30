/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function (obj, classFunction) {
  return (![null, undefined].includes(obj) && ![null, undefined].includes(classFunction) && typeof classFunction === 'function' && Object(obj) instanceof classFunction);
};
