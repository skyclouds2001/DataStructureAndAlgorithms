#!/usr/bin/env node

/**
 * @file personal promise accomplish
 * @version 0.0.0
 * @author skyclouds2001 <skyclouds2001@163.com>
 * @copyright skyclouds2001 2023-present
 * @license MIT
 * @since 0.0.0
 * @see {@link https://github.com/promises-aplus/promises-tests}
 */

const assert = require("node:assert")
const { describe, it, mock, afterEach, beforeEach } = require("node:test")

/**
 * personal promise accomplish
 */
class _Promise {
  /**
   * @type {'pending'}
   * @private
   * @static
   * @readonly
   */
  static PENDING = 'pending'

  /**
   * @type {'fulfilled'}
   * @private
   * @static
   * @readonly
   */
  static FULFILLED = 'fulfilled'

  /**
   * @type {'rejected'}
   * @private
   * @static
   * @readonly
   */
  static REJECTED = 'rejected'

  static get [Symbol.species]() {
    return this
  }

  static get [Symbol.toStringTag]() {
    return '_Promise'
  }

  /**
   * @param {(resolve: (result: any) => void, reject: (reason: any) => void) => void} executor
   * @public
   */
  constructor(executor) {
    this.status = _Promise.PENDING
    this.result = undefined
    this.reason = undefined

    this.onFulfilledCallbacks = []
    this.onRejectedCallbacks = []

    /**
     * @param {any} result
     * @returns {void}
     */
    const resolve = (result) => {
      _Promise.resolvePromise(this, result, result => {
        if (this.status === _Promise.PENDING) {
          this.status = _Promise.FULFILLED
          this.result = result
          this.onFulfilledCallbacks.forEach(fn => {
            fn()
          })
        }
      }, reason => {
        reject(reason)
      })
    }

    /**
     * @param {any} reason
     * @returns {void}
     */
    const reject = (reason) => {
      if (this.status === _Promise.PENDING) {
        this.status = _Promise.REJECTED
        this.reason = reason
        this.onRejectedCallbacks.forEach(fn => {
          fn()
        })
      }
    }

    try {
      executor(resolve, reject)
    } catch (err) {
      reject(err)
    }
  }

  /**
   * @type {'pending' | 'fulfilled' | 'rejected'}
   * @public
   */
  status

  /**
   * @type {any}
   * @public
   */
  result

  /**
   * @type {any}
   * @public
   */
  reason

  /**
   * @type {Array<() => void>}
   * @private
   */
  onFulfilledCallbacks

  /**
   * @type {Array<() => void>}
   * @private
   */
  onRejectedCallbacks

  /**
   * @param {(result: any) => void | null | undefined} onFulfilled
   * @param {(reason: any) => void | null | undefined} onRejected
   * @returns {_Promise}
   * @public
   */
  then(onFulfilled, onRejected) {
    if (typeof onFulfilled !== 'function') {
      onFulfilled = result => result
    }

    if (typeof onRejected !== 'function') {
      onRejected = reason => {
        throw reason
      }
    }

    const promise = new _Promise((resolve, reject) => {
      const handleOnFulfilled = () => {
        setTimeout(() => {
          try {
            const res = onFulfilled(this.result)
            _Promise.resolvePromise(promise, res, resolve, reject)
          } catch (error) {
            reject(error)
          }
        }, 0)
      }

      const handleOnRejected = () => {
        setTimeout(() => {
          try {
            const res = onRejected(this.reason)
            _Promise.resolvePromise(promise, res, resolve, reject)
          } catch (error) {
            reject(error)
          }
        }, 0)
      }

      if (this.status === _Promise.FULFILLED) {
        handleOnFulfilled()
      }

      if (this.status === _Promise.REJECTED) {
        handleOnRejected()
      }

      if (this.status === _Promise.PENDING) {
        this.onFulfilledCallbacks.push(handleOnFulfilled)
        this.onRejectedCallbacks.push(handleOnRejected)
      }
    })

    return promise
  }

  /**
   * @param {(reason: any) => void | null | undefined} onRejected
   * @returns {_Promise}
   * @public
   */
  catch(onRejected) {
    return this.then(null, onRejected)
  }

  /**
   * @param {() => any} onFinally
   * @returns {_Promise}
   * @public
   */
  finally(onFinally) {
    return this.then((value) => {
      return Promise.resolve(onFinally()).then(() => value)
    }, (reason) => {
      return Promise.resolve(onFinally()).then(() => {
        throw reason
      })
    })
  }

  /**
   * @param {any} result
   * @returns {_Promise}
   * @public
   * @static
   */
  static resolve(result) {
    return new _Promise((resolve, reject) => {
      resolve(result)
    })
  }

  /**
   * @param {any} reason
   * @returns {_Promise}
   * @public
   * @static
   */
  static reject(reason) {
    return new _Promise((resolve, reject) => {
      reject(reason)
    })
  }

  /**
   * @param {{ [Symbol.iterator]: Function }} promises
   * @returns {_Promise}
   * @public
   * @static
   */
  static all(promises) {
    const size = promises.length
    const results = Array(size)
    let count = 0

    return new _Promise((resolve, reject) => {
      if (size === 0) {
        resolve([])
      }

      promises.forEach((promise, index) => {
        _Promise.resolve(promise).then(result => {
          results[index] = result
          ++count

          if (count === size) {
            resolve(results)
          }
        }, reason => {
          reject(reason)
        })
      })
    })
  }

  /**
   * @param {{ [Symbol.iterator]: Function }} promises
   * @returns {_Promise}
   * @public
   * @static
   */
  static allSettled(promises) {
    const size = promises.length
    const results = Array(size)
    let count = 0

    return new _Promise((resolve, reject) => {
      if (size === 0) {
        resolve([])
      }

      promises.forEach((promise, index) => {
        _Promise.resolve(promise).then(value => {
          results[index] = {
            status: 'fulfilled',
            value,
          }
          ++count

          if (count === size) {
            resolve(results)
          }
        }, reason => {
          results[index] = {
            status: 'rejected',
            reason,
          }
          ++count

          if (count === size) {
            resolve(results)
          }
        })
      })
    })
  }

  /**
   * @param {{ [Symbol.iterator]: Function }} promises
   * @returns {_Promise}
   * @public
   * @static
   */
  static any(promises) {
    const size = promises.length
    const results = Array(size)
    let count = 0

    return new _Promise((resolve, reject) => {
      if (size === 0) {
        reject([])
      }

      promises.forEach((promise, index) => {
        _Promise.resolve(promise).then(value => {
          resolve(value)
        }, reason => {
          results[index] = reason
          ++count

          if (count === size) {
            reject(results)
          }
        })
      })
    })
  }

  /**
   * @param {{ [Symbol.iterator]: Function }} promises
   * @returns {_Promise}
   * @public
   * @static
   */
  static race(promises) {
    return new _Promise((resolve, reject) => {
      promises.forEach(promise => {
        _Promise.resolve(promise).then(result => {
          resolve(result)
        }, reason => {
          reject(reason)
        })
      })
    })
  }

  /**
   * @param {_Promise} promise
   * @param {any} response
   * @param {(result: any) => void} resolve
   * @param {(reason: any) => void} reject
   * @returns {void}
   * @private
   * @static
   */
  static resolvePromise(promise, response, resolve, reject) {
    if (promise === response) {
      return reject(new TypeError('Chaining cycle detected for promise'))
    }

    if (response === null || typeof response !== 'object' && typeof response !== 'function') {
      resolve(response)
    }

    let called = false

    try {
      const { then } = response

      if (typeof then !== 'function') {
        resolve(response)
      }

      then.call(response, (result) => {
        if (called) return
        called = true

        _Promise.resolvePromise(promise, result, resolve, reject)
      }, (reason) => {
        if (called) return
        called = true

        reject(reason)
      })
    } catch (err) {
      if (called) return
      called = true

      reject(err)
    }
  }
}

/***** test *****/

describe('Promise', () => {
  const fn = mock.fn()

  const sleep = (timeout) => {
    return new Promise((resolve) => {
      setTimeout(() => {
        resolve()
      }, timeout);
    })
  }

  beforeEach(() => {
    fn.mock.restore()
  })

  afterEach(() => {
    fn.mock.restore()
  })

  describe('The Promise Resolution Procedure', () => {
    describe('If promise and x refer to the same object, reject promise with a TypeError as the reason', () => {
      it('with a fulfilled promise', async () => {
        const promise = new _Promise((resolve, reject) => {
          resolve()
        }).then(() => promise, null)

        await sleep(100)

        promise.then(null, (reason) => {
          assert(reason instanceof TypeError)
        })

        await sleep(100)
      })

      it('with a rejected promise', async () => {
        const promise = new _Promise((resolve, reject) => {
          reject()
        }).then(null, () => promise)

        await sleep(100)

        promise.then(null, (reason) => {
          assert(reason instanceof TypeError)
        })

        await sleep(100)
      })
    })
  })
})
