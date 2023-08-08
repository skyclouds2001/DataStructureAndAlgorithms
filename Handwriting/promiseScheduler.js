class PromiseScheduler {
  queue = []
  max = 2
  run = 0

  add(fn) {
    this.queue.push(fn)
    this.exec()
  }

  exec() {
    if (this.queue.length > 0 && this.run < this.max) {
      const fn = this.queue.shift()
      ++this.run

      fn().then(() => {
        --this.run
        this.exec()
      })
    }
  }
}

const timeout = time => {
  return new Promise(resolve => {
    setTimeout(resolve, time)
  })
}
  
const scheduler = new PromiseScheduler()
  
const addTask = (time,order) => {
  scheduler.add(() => timeout(time).then(() => console.log(order)))
}

addTask(1000, '1')
addTask(500, '2')
addTask(300, '3')
addTask(400, '4')
