/**
 * @param {Function} fn
 * @param {number} delay
 * @param  {...any} args
 * @returns {Function}
 */
function setInterval(fn, delay, ...args) {
  let timer = null

  function interval() {
    fn(...args)
    timer = setTimeout(interval, delay)
  }

  interval()

  return function() {
    if (timer) clearTimeout(timer)
  }
}

const cancel = setInterval(() => {
  console.log(1)
}, 300)

setTimeout(() => {
  cancel()
}, 1000)
