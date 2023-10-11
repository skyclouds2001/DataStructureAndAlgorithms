/**
 * 图像数据
 * 0 1 0 0 2
 * 1 2 1 2 1
 * 1 0 1 0 0
 * 0 1 2 0 0
 * 1 1 0 0 2
 *
 * 卷积核矩阵
 * 0 1 1
 * 0 0 1
 * 1 1 0
 *
 * 卷积框位置索引 卷积框宽高 填充数 卷积步长
 * 0 0 3 3 0 1
 */

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let step = 0
let list1: number[][]
let list2: number[][]
let list3: [number, number, number, number, number, number]

rl.on('line', function (line) {
    ++step

    switch (step) {
        case 1:
            list1 = JSON.parse(line.trim())
            break
        case 2:
            list2 = JSON.parse(line.trim())
            break
        case 3:
            list3 = JSON.parse(line.trim())
            break
    }

    if (step !== 3) {
        return
    }

    console.log(list3[4], list3[3])
});
