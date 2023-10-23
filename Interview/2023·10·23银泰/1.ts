/// <reference lib="esnext" />

/**
 * s1 和 s2 最长公共子序列的长度
 * @param s1 string字符串
 * @param s2 string字符串
 * @return int整型
 */
export function LCS(s1: string, s2: string): number {
    const l1 = s1.length
    const l2 = s2.length
    const dp = Array(l1 + 1).fill(0).map(() => Array(l2 + 1).fill(0))

    let ans = 0

    for (let i = 1; i <= l1; ++i) {
        for (let j = 1; j <= l2; ++j) {
            if (s1[i] === s2[j]) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
            }
        }
    }

    ans = dp[l1][l2]

    return ans
}
