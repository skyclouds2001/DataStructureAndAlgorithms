// @ts-check
/// <reference path="./template.d.ts" />

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

rl.on('line', function (data) {
    if (n === 0) {
        n = Number.parseInt(data)
        k = 0
        maps = Array(n).fill(0).map(() => new Map())
    } else if (k < n) {
        ++k

        let areas = data.split('/')
        for (let i = 0; i < areas.length; ++i) {
            if (!maps[i].has(areas[i])) {
                maps[i].set(areas[i], 0)
            }
            ++maps[i][areas[i]]
        }
    } else {
        let str = data.split(' ')
        let level = Number.parseInt(str[0])
        let target = str[1]

        let map = maps[level]
        let cnt = map[target]

        console.log(cnt)
    }
})

let n = 0
let k = 0
let maps = null
