/**
 * @param {Array} array
 * @returns {Array}
 */
function removeDuplicated(array) {
    return Array.from(new Set(array))
}

/**
 * @param {Array} array
 * @returns {Array}
 */
function removeDuplicated(array) {
    const obj = {}
    array.forEach(val =>
        obj[val] = 0
    )
    return Object.keys(obj).map(val => Number(val))
}

/**
 * @param {Array} array
 * @returns {Array}
 */
function removeDuplicated(array) {
    return array.reduce((pre, cur) => pre.includes(cur) ? pre : [...pre, cur], [])
}

/**
 * @param {number} m
 * @param {number} n
 * @returns {number}
 */
function exec(m, n) {
    if (m === 1 && n === 1) {
        return 1
    }
    if (n === 1 || n === m) {
        return 1
    }
    return exec(m - 1, n - 1) + exec(m - 1, n)
}

console.log(exec(6,3))
console.log(judge('()'))
console.log(judge('([)]'))

/**
 * @param {string} s
 * @returns {boolean}
 */
function judge(s) {
    const stack = []
    for (const c of s) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                stack.push(c)
                break
            case ')':
                const cccc = stack.pop()
                if (cccc != "(") {
                    return false
                }
                break
            case ']':
                const cc = stack.pop()
                if (cc != "[") {
                    return false
                }
                break
            case '}':
                const ccc = stack.pop()
                if (ccc != "}") {
                    return false
                }
                break
        }
    }

    if (stack.length > 0) {
        return false
    }

    return true
}
