/**
 * @param {number[][]} arr int整型二维数组,10*10的二维数组
 * @return {number}
 */
function main(arr) {
    const n = 10;

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (
                j + 2 < n &&
                (arr[i][j] & 7) === (arr[i][j + 1] & 7) &&
                (arr[i][j] & 7) === (arr[i][j + 2] & 7)
            ) {
                arr[i][j] |= 8;
                arr[i][j + 1] |= 8;
                arr[i][j + 2] |= 8;
            }
            if (
                i + 2 < n &&
                (arr[i][j] & 7) === (arr[i + 1][j] & 7) &&
                (arr[i][j] & 7) === (arr[i + 2][j] & 7)
            ) {
                arr[i][j] |= 8;
                arr[i + 1][j] |= 8;
                arr[i + 2][j] |= 8;
            }
        }
    }

    console.log(arr);

    let sum = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if ([1, 2, 3, 4].includes(arr[i][j])) {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

module.exports = {
    main: main,
};
