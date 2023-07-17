// Time:  O(n)
// Space: O(h)

// dfs
function undefinedToNull(obj: Record<any, any>): Record<any, any> {
    Object.keys(obj).forEach(key => {
        if (typeof obj[key] === 'object' && obj[key] !== null) {
            obj[key] = undefinedToNull(obj[key]);
        } else {
            obj[key] = obj[key] ?? null;
        }
    });
    return obj;
};
