class EventEmitter {
  /**
   * @type {Map<string, Function[]>}
   */
  events = new Map()

  /**
   * @param {string} event
   * @param {Function} callback
   * @returns {EventEmitter}
   */
  on(event, callback) {
    if (!this.events.has(event)) {
      this.events.set(event, [])
    }

    this.events.get(event)?.push(callback)

    return this
  }

  /**
   * @param {string | null | undefined} event
   * @param {Function | null | undefined} callback
   * @returns {EventEmitter}
   */
  off (event, callback) {
    if (event == null && callback == null) {
      this.events.clear()
    } else if (event != null && callback == null) {
      this.events.delete(event)
    } else if (event != null && callback != null) {
      const index = this.events.get(event)?.indexOf(callback)
      if (index != null && index != -1) {
        this.events.get(event)?.splice(index, 1)
      }
    }

    return this
  }

  /**
   * @param {string} event
   * @param  {...any} payload
   * @returns {EventEmitter}
   */
  emit(event, ...payload) {
    this.events.get(event)?.forEach((fn) => fn.apply(this, payload))

    return this
  }

  /**
   * @param {string} event
   * @param {Function} callback
   * @returns {EventEmitter}
   */
  once(event, callback) {
    this.on(event, (...payload) => {
      callback.apply(this, payload)
      this.off(event, callback)
    })

    return this
  }
}
