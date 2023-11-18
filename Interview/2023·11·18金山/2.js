const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

let n, m

void async function () {
    // Write your code here
    while(line = await readline()){
        const tokens = line.split(' ')

        if (n == null || m == null) {
            n = Number.parseInt(tokens[0])
            m = Number.parseInt(tokens[1])

            continue
        }

        const arr = tokens.map(v => Number.parseInt(v))
        const sym = Array(n).fill(0)
        let count = 0
        let teach = 1

        // modify process
        while(count < n) {
            // find max
            let max
            let t = 0
            for (let i = 0; i < n; ++i) {
                if (sym[i] === 0 && arr[i] > t) {
                    max = i
                    t = arr[i]
                }
            }

            // set current val
            let cnt
            let index
            sym[max] = teach
            count += 1

            // set right val
            cnt = 0
            index = max
            while (cnt < m && index < n) {
                if (sym[index] === 0) {
                    sym[index] = teach
                    ++cnt
                }
                ++index
            }
            count += cnt

            // set left val
            cnt = 0
            index = max
            while (cnt < m && index >= 0) {
                if (sym[index] === 0) {
                    sym[index] = teach
                    ++cnt
                }
                --index
            }
            count += cnt

            // reset teach
            teach = teach % 2 + 1
        }

        // resolve result
        const res = Array(n)
        for (let i = 0; i < n; ++i) {
            if (sym[i] === 1) {
                res[i] = 'A'
            }
            if (sym[i] === 2) {
                res[i] = 'B'
            }
        }

        // log result
        console.log(res.join(''))
    }
}()
