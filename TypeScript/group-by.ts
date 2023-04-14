// Time:  O(n)
// Space: O(n)

declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

// hash table
Array.prototype.groupBy = function(fn) {
    const lookup = {};
    for (const val of this) {
        const key = fn(val);
        lookup[key] ||= []
        lookup[key].push(val);
    }
    return lookup;
}
