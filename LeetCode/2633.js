/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
  if (Array.isArray(object)) {
      return `[${object.map(v => jsonStringify(v)).join(',')}]`;
  } else if (typeof object === 'object' && object !== null) {
      return `{${Object.keys(object)
          .reduce((pre, cur) => [...pre, `"${cur}":${jsonStringify(object[cur])}`], [])
          .join(',')}}`;
  } else if (typeof object === 'string') {
      return `"${object}"`;
  } else {
      return String(object);
  }
};
