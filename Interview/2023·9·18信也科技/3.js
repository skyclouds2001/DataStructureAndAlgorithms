/**
 * 翻转函数
 * @param {string} sentence string字符串 
 * @return {string} string字符串
 */
function reverseSentence(sentence) {
  return sentence.split(' ').map((v) => v.split('').reverse().join('')).join(' ')
}

module.exports = {
  reverseSentence,
}
