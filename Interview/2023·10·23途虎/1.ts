/**
 * 找出车辆可能的故障原因
 * @param keywords string字符串一维数组 故障原因关键词
 * @param faults string字符串二维数组 故障原因列表
 * @return string字符串一维数组
 */
export function findFaults(keywords: string[], faults: string[][]): string[] {
    const arr = faults.map((fault) => ({
        fault,
        cnt: fault.reduce(
            (cnt, v, i) => cnt + (i !== 0 && keywords.includes(v) ? 1 : 0),
            0
        ),
    }));

    arr.sort((a, b) => b.cnt - a.cnt);

    return arr.filter(v => v.cnt > 0).map(v => v.fault[0]);
}
