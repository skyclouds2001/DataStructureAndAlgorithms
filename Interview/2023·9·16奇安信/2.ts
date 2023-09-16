/// <reference lib="esnext" />

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

const iter = rl[Symbol.asyncIterator]()

const getLine = () => iter.next()

void async function () {
    let line: IteratorResult<string> = await getLine()
    const tree: number[] = line.value.split(',').map(v => Number.parseInt(v))
    const ans: number[] = []

    while (!line.done) {
        line = await getLine()
        if (line.done) {
            break
        }

        const [a, b]: [number, number] = line.value.split(',').map((v: string) => Number.parseInt(v))

        let n = a // 当前遍历下标

        let r = n ^ b // 当前遍历最大值
        let id = a // 当前遍历最大值下标

        while (true) {
            n = tree[n]

            if (n == -1) {
                break
            }

            if ((n ^ b) > r) {
                id = n
                r = n ^ b
            }
        }

        ans.push(id)
    }

    console.log(ans.join(','))
}()
