// 现场编程题题目内容：给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
// 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
// 假设环境不允许存储 64 位整数（有符号或无符号）。
// 示例 1：
// 输入：x = 123
// 输出：321
// 示例 2：
// 输入：x = -123
// 输出：-321
// 示例 3：
// 输入：x = 120
// 输出：21
// 示例 4：
// 输入：x = 0
// 输出：0
// 提示：
// -2^31 <= x <= 2^31 – 1

function reverser_integer(x) {
  const sym = x >= 0
  let res = 0
  let t = Math.abs(x)

  const INT_MAX = 0x7fffffff

  while (t != 0) {
    if (res > (INT_MAX - t % 10) / 10) {
      return 0
    }
    res *= 10
    res += (t % 10)
    t = Math.floor(t / 10)
  }

  return (sym ? 1 : -1) * res
}

// console.log(reverser_integer(123))
// console.log(reverser_integer(-123))
// console.log(reverser_integer(120))
// console.log(reverser_integer(0))
console.log(reverser_integer(123456789))
console.log(reverser_integer(120))
console.log(reverser_integer(-120))
console.log(reverser_integer(1294967299))
// 123456789
// 120
// -120
