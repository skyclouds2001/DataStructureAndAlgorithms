class EventEmitter {
  #events = new Map()

  subscribe(event, cb) {
    if (!this.#events.has(event)) {
      this.#events.set(event, [])
    }

    this.#events.get(event).push(cb)

    return {
      unsubscribe: () => {
        this.#events.get(event).splice(this.#events.get(event).indexOf(cb), 1)
      }
    };
  }

  emit(event, args = []) {
    return (this.#events.get(event) ?? []).map((cb) => cb(...args))
  }
}
