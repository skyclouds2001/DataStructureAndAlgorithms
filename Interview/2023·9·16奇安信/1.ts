/// <reference lib="esnext" />

/**
 * @param nums int整型二维数组 一段时间内的中奖号码数组
 * @return int整型一维数组
 */
export function getLuckyNum(nums: number[][]): number[] {
    const map: number[] = Array(33).fill(0)
    // k 数字 0-32 v 数字出现次数

    for (const num of nums.flat()) {
        ++map[num - 1]
    }

    console.log(map)

    const count: Record<number, number> = {}
    // k 数字出现次数 v 数字出现次数的次数
    for (const c of map) {
        if (!(c in count)) {
            count[c] = 0
        } else {
            ++count[c]
        }
    }

    console.log(count)

    const res: number[] = []
    // 数字出现次数的次数
    let c = 0
    for (const k in count) {
        if (!Number.isNaN(Number(k))) {
            c += count[k]
            res.push(Number(k))

            if (c >= 7) {
                break
            }
        }
    }
    res.sort((a, b) => a - b)

    console.log(res)

    const ans: number[] = []
    // 数字 0-32
    for (const val of res) {
        map.forEach((v, i) => {
            if (val === v && ans.length < 7) {
                ans.push(i)
            }
        })
        if (ans.length >= 7) {
            break
        }
    }
    ans.sort((a, b) => a - b)

    return ans.map(v => v + 1);
}
