/**
 * @typedef {object} NodeJson
 * @property {string} tag
 * @property {NodeJson[]} children
 */

/**
 * @param {HTMLElement} dom
 * @returns {NodeJson}
 */
function transform(dom) {
  return {
    tag: dom.nodeName,
    children: dom.childNodes.map((node) => transform(node)),
  }
}
