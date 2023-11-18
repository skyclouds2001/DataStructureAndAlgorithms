const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    let H, x
    let sum = 0

    const map = new Map()

    const MOD = 1000000000 + 7

    let line
    let height = 1
    while (line = await readline()) {
        if (H == null || x == null) {
            const tokens = line.split(' ')

            H = Number.parseInt(tokens[0])
            x = Number.parseInt(tokens[1])

            for (let i = 0, t = 1; i <= H; ++i) {
                map.set(i, t)
                t *= x % MOD
            }

            continue
        }

        const number = Number.parseInt(line)

        sum += (map.get(height) % MOD) * number % MOD

        if (height === H) {
            console.log(sum)
        }

        ++height
    }
}()
