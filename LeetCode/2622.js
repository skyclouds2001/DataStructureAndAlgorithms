var TimeLimitedCache = function() {
    this.data= {}
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const current = Date.now()
    const raw = this.data[key]
    this.data[key] = { key, value, duration, timestamp: current }
    return raw !== undefined && raw.timestamp + raw.duration >= current
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const current = Date.now()
    const raw = this.data[key]
    return raw && raw.timestamp + raw.duration >= current ? raw.value : -1
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const current = Date.now()
    return Object.entries(this.data).filter(([k, v]) => v.timestamp + v.duration >= current).length
};
