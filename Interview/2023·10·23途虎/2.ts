/**
 * @param arr_string string字符串 字符串数据
 * @return int整型
 */
export function sum_func(arr_string: string): number {
    const arr = JSON.parse(arr_string)

    return arr.flat(Infinity).reduce((sum, val) => sum + ((val % 2 == 0) ? val : 0), 0)
}
