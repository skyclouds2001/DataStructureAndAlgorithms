type F = (...args: any[]) => void

function throttle(fn: F, t: number): F {
    let flag = false
    let arg: any[] | null = null
    const handle = () => {
        if (arg) {
            fn(...arg)
            arg = null
            setTimeout(handle, t)
        } else {
            flag = false
        }
    }
    return function (...args) {
        if (!flag) {
            fn(...args)
            flag = true
            setTimeout(handle, t)
        } else {
            arg = args
        }
    }
};
