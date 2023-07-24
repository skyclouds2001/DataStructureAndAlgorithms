/**
 * @param {number[]} nums
 */
var ArrayWrapper = function(nums) {
    this.nums = nums.flat(Infinity)
};

ArrayWrapper.prototype.valueOf = function() {
    return this.nums.reduce((pre, cur) => pre + cur, 0)
}

ArrayWrapper.prototype.toString = function() {
    return `[${this.nums.join(',')}]`
}
