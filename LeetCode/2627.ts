type F = (...p: any[]) => any

function debounce(fn: F, t: number): F {
    let id: ReturnType<typeof setTimeout> | null = null
    return function(...args) {
        if (id) {
            clearTimeout(id)
            id = null
        }
        id = setTimeout(fn, t, ...args)
    }
}
