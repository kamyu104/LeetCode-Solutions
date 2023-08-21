// Time:  O(n)
// Space: O(h)

// dfs
function deepFilter(obj: Record<string, any>, fn: Function): Record<string, any> | undefined {
    if (typeof obj !== 'object' || obj === null) {
        return fn(obj) ? obj : undefined;
    }
    if (Array.isArray(obj)) {
        const result = obj.map(x => deepFilter(x, fn)).filter(x => x !== undefined);
        return result.length !== 0 ? result : undefined;
    }
    const result = {};
    for (const key in obj) {
        const value = deepFilter(obj[key], fn);
        if (value !== undefined) {
            result[key] = value;
        }
    }
    return Object.keys(result).length !== 0 ? result : undefined;
};
