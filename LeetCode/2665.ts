type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
};

function createCounter(init: number): ReturnObj {
    let value = init;
    return {
        increment: () => ++value,
        decrement: () => --value,
        reset: () => (value = init),
    };
};
