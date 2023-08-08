/**
 * @param {number} timeout
 * @returns {Promise<void>}
 */
function sleep(timeout) {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve()
    }, timeout);
  })
}

(async () => {
  const now = Date.now()
  console.log(Date.now() - now)

  await sleep(0)
  console.log(Date.now() - now)

  await sleep(1000)
  console.log(Date.now() - now)
})()
