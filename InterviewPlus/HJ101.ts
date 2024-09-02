const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n: number | null = null
let nums: number[] | null = null

rl.on('line', function (line: string) {
    if (n == null) {
        n = Number.parseInt(line.trim())
    } else if (nums == null) {
        nums = line.trim().split(' ').map(v => Number.parseInt(v))
    } else {
        const status = Number.parseInt(line.trim())
        console.log(nums.sort((a, b) => status === 0 ? a - b : b - a).join(' '))
    }
});
