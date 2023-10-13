/**
 * 语句排序
 * @param text {string} string字符串
 * @return {string}
 */
function arrangeWords(text) {
    const words = text.split(' ')
    const size = words.length

    function swap(x, y) {
        let t = words[x]
        words[x] = words[y]
        words[y] = t

        if (x === b) {
            b = y
        }
        if (y === b) {
            b = x
        }
    }

    let b = 0

    for (let i = 0; i < size; ++i) {
        for (let j = 0; j < size; ++j) {
            if (words[i].length > words[j].length) {
                swap(i, j)
            } else if (words[i].length === words[j].length) {
                if (words[i] > words[j]) {
                    swap(i, j)
                }
            }
        }
    }

    words[b] = words[b].slice(0, 1).toUpperCase() + words[b].slice(1)
    words[0] = words[0].slice(0, 1).toUpperCase() + words[0].slice(1)

    return words.join(' ')
}

module.exports = {
    arrangeWords,
}
