// Time:  O(1)
// Space: O(1)

type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    let lookup = new Map();
    return (...args) => {
        const key = args.join();
        if (!lookup.has(key)) {
            lookup.set(key, fn(...args))
        }
        return lookup.get(key);
    }
}
