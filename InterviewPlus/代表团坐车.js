const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n = null
let V = 0;

rl.on('line', function (data) {
    if (n == null) {
        n = data.split(',').map(v => Number.parseInt(v))
    } else {
        let N = n.length
        V = Number.parseInt(data)
        let dp = Array(N + 1).fill(0).map(() => Array(V + 1))
        for (let i = 0; i <= N; ++i) dp[i][0] = 1

        for (let i = 1; i <= N; ++i)
            for (let j = n[i]; j <= V; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - n[i]]

        console.log(dp[N][V])
    }
})
