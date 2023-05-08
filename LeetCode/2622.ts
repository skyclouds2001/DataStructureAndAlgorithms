interface Data {
    key: number;
    value: number;
    duration: number;
    timestamp: number;
}

class TimeLimitedCache {
    private data: Record<string, Data> = {};
    private timestamp: number = Date.now();

    constructor() {}

    set(key: number, value: number, duration: number): boolean {
        const current = Date.now()
        const raw = this.data[key]
        this.data[key] = { key, value, duration, timestamp: current }
        return raw !== undefined && raw.timestamp + raw.duration >= current
    }

    get(key: number): number {
        const current = Date.now()
        const raw = this.data[key]
        return raw && raw.timestamp + raw.duration >= current ? raw.value : -1
    }

	count(): number {
        const current = Date.now()
        return Object.entries(this.data).filter(([k, v]) => v.timestamp + v.duration >= current).length
    }
}
