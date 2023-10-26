function topKFrequent( nums ,  k ) {
  const m = new Map()

  for (const num of nums) {
    if (!m.has(num)) {
      m.set(num, 0)
    }

    m.set(num, m.get(num) + 1)
  }

  const es = Array.from(m.entries())

  es.sort((a, b) => b[1] - a[1])

  return es.slice(0, k).map(v => v[0])
}

module.exports = {
  topKFrequent,
}
