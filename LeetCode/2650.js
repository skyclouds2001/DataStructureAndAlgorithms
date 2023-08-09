/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
var cancellable = function(generator) {
    let cancel

    const promise = new Promise(async (resolve, reject) => {
      cancel = async () => {
        try {
          const p = generator.throw('Cancelled')

          const v = await p.value

          resolve(v)
        } catch (error) {
          reject(error)
        }
      }

      try {
        let p = generator.next()

        while (!p.done) {
          try {
            const v = await p.value

            p = generator.next(v)
          } catch (error) {
            p = generator.throw(error)
          }
        }

        const v = await p.value

        resolve(v)
      } catch (error) {
        reject(error)
      }
    })

    return [cancel, promise]
};

/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
var cancellable = function(generator) {
    let cancel

    const promise = new Promise(async (resolve, reject) => {
      cancel = () => {
        run(undefined, 'Cancelled')
      }

      const run = (res, error) => {
        try {
          const { value, done } = error ? generator.throw(error) : generator.next(res)
          if (done) {
            resolve(value)
            return
          } else {
            value.then((value) => {
              run(value)
            }).catch((error) => {
              run(undefined, error)
            })
          }
        } catch (error) {
          reject(error)
        }
      }

      run()
    })

    return [cancel, promise]
};

