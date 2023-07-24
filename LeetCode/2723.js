/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  return Promise.allSettled([promise1, promise2]).then(([v1, v2]) => v1.value + v2.value)
}
