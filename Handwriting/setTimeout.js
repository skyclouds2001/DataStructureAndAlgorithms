/**
 * @param {Function} fn
 * @param {number} delay
 * @param  {...any} args
 * @returns {Function}
 */
function setTimeout(fn, delay, ...args) {
  let timer = null
  
  timer = setInterval(() => {
    if (timer) clearInterval(timer)
    timer = null
    fn(...args)
  }, delay)

  return function() {
    if (timer) clearInterval(timer)
    timer = null
  }
}

const cancel = setTimeout(() => {
  console.log(1)
}, 1000)

setTimeout(() => {
  cancel()
}, 900)
