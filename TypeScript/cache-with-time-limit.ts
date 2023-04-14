// Time:  O(1)
// Space: O(1)

// hash table
interface Value {
    value: number;
    tid: ReturnType<typeof setTimeout>;
}

class TimeLimitedCache {
    private lookup: Map<number, Value>;

    constructor () {
       this.lookup = new Map();
    }

    set(key: number, value: number, duration: number): boolean {
        const found = this.lookup.has(key)
        if (found) {
            clearTimeout(this.lookup.get(key).tid)
        };
        this.lookup.set(key, {
            value: value,
            tid: setTimeout(() => this.lookup.delete(key), duration)
        });
        return found;
    }

    get(key: number): number {
        return this.lookup.has(key) ? this.lookup.get(key).value : -1;
    }

    count(): number {
        return this.lookup.size;
    }
}
