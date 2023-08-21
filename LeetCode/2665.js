/**
 * @param init {number}
 * @return {Record<'increment' | 'decrement' | 'reset', () => number>}
 */
var createCounter = function (init) {
    let value = init;

    return {
        increment: () => ++value,
        decrement: () => --value,
        reset: () => (value = init),
    };
};
