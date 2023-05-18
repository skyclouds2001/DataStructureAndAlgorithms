/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let count = 0;
    const len = s.length;

    for (let i = 0; i < 2 * len - 1; ++i) {
        const l = Math.floor(i / 2);
        const r = Math.ceil(i / 2);
        let j = 0;
        while (l - j >= 0 && r + j < len && s[l - j] === s[r + j]) ++j;
        count += j;
    }

    return count;
};
