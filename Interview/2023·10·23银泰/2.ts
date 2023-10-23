/**
 * 最大数
 * @param nums int整型一维数组
 * @return string字符串
 */
export function solve(nums: number[]): string {
    const strs = nums.map(num => num.toString())

    strs.sort(compare)

    return strs.reverse().join('')

    function compare(a: string, b: string) {
        if (a.length == b.length) {
            return a < b ? -1 : 1;
        } else if (a.length < b.length) {
            const mil = a.length
            const mal = b.length

            if (a === b.slice(0, mil)) {
                return a.slice(0, mal - mil) < b.slice(mil) ? -1 : 1;
            }

            return a < b ? -1 : 1;
        } else if (a.length > b.length) {
            const mil = b.length
            const mal = a.length

            if (a.slice(0, mil) === b) {
                return a.slice(mil) < b.slice(0, mal - mil) ? -1 : 1;
            }
            // 2000020 20000
            // 2000010 20000

            return a < b ? -1 : 1;
        }

        return 0
    }
}
