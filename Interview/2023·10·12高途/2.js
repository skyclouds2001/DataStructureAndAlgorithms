function calculate(costs) {
    const size = costs.length
    let index = 0
    let sum = 0
    let ans = 0

    while (index < size) {
        if (sum < 0) {
            sum = 0
        }

        sum += costs[index]
        ans = ans > sum ? ans : sum
        index += 1
    }

    return ans
}
