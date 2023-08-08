/**
 * @param {Function} fn
 * @returns {(...args: any[]) => any}
 */
function firstPromise(fn) {
  let p = null
  return function(...args) {
    if (!p) {
      p = fn.apply(this, args).finally(() => {
        p = null
      })
    }
    return p
  }
}

let count = 1

let promiseFunction = () =>
  new Promise((resolve) =>
    setTimeout(() => {
      resolve(count++)
    }, 1000)
  )

let fn = firstPromise(promiseFunction)

fn().then(console.log)
fn().then(console.log)
fn().then(console.log)

setTimeout(() => {
  fn().then(console.log)
  fn().then(console.log)
  fn().then(console.log)
}, 3000)
