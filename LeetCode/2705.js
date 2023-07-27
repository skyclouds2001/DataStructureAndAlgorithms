/**
 * @param {Object} obj
 * @return {Object}
 */
var compactObject = function (obj) {
  return Array.isArray(obj) ?
    obj.filter(v => Boolean(v))
      .map(v => typeof v === 'object' && v !== null
        ? compactObject(v) :
        v
      ) :
    Object.fromEntries(
      Object.entries(obj)
        .filter(([_, value]) => Boolean(value))
        .map(([key, value]) => [key, typeof value === 'object' && value !== null ?
          compactObject(value) :
          value
        ])
    )
}
