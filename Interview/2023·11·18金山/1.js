const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void async function () {
    var line;
    while (line = await readline()) {
        const len = line.length
        let y = 0
        let f = 0

        for (const c of line) {
            if (['a', 'e', 'i', 'o', 'u'].includes(c)) {
                ++y
            } else {
                ++f
            }
        }

        if (f > y + 1) {
            console.log(y + 1 + y)
        } else {
            console.log(len)
        }
    }
}()
