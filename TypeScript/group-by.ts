// Time:  O(n)
// Space: O(1)

declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

// hash table
Array.prototype.groupBy = function(fn) {
    let lookup = {};
    for (const val of this) {
        const key = fn(val);
        lookup[key] ||= [];
        lookup[key].push(val);
    }
    return lookup;
}
