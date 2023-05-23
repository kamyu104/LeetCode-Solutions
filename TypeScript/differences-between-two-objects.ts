// Time:  O(n)
// Space: O(h)

// dfs
function objDiff(obj1: any, obj2: any): any {
    let result = {};
    for (let key in obj1) {
        if (!(key in obj2)) {
            continue;
        }
        if (typeof obj1[key] === 'object' && typeof obj2[key] === 'object' && Array.isArray(obj1[key]) === Array.isArray(obj2[key])) {
            result[key] = objDiff(obj1[key], obj2[key]);
            if (Object.keys(result[key]).length === 0) {
                delete result[key];
            }
        } else if (obj1[key] !== obj2[key]) {
            result[key] = [obj1[key], obj2[key]];
        }
    }
    return result;
};
