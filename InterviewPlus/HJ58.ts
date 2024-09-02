const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n: number | null = null
let k: number | null = null

rl.on('line', function (line: string) {
    if (n == null || k == null) {
        const nums = line.trim().split(' ')
        n = Number.parseInt(nums[0])
        k = Number.parseInt(nums[1])
    } else {
        console.log(line.trim().split(' ').map(v => Number.parseInt(v)).sort((a, b) => a - b).slice(0, k).join(' '))
    }
});
