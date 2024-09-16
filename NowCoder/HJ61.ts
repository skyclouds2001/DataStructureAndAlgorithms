const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

rl.on('line', function (data: string) {
  const [m, n] = data.trim().split(" ").map(v => Number.parseInt(v))

  const dp = Array(m + 1).fill(0).map(_ => Array(n + 1).fill(0))

  for (let i = 0; i <= m; ++i) {
    dp[i][0] = 1;
    dp[i][1] = 1;
  }
  for (let j = 0; j <= n; ++j) {
    dp[0][j] = 1;
    dp[1][j] = 1;
  }

  for (let i = 2; i <= m; ++i) {
    for (let j = 2; j <= n; ++j) {
        if (i < j) {
            dp[i][j] = dp[i][i];
        } else {
            dp[i][j] = dp[i - j][j] + dp[i][j - 1];
        }
    }
  }

  console.log(dp[m][n])
})
