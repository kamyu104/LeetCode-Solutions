// Time:  O(n + m)
// Space: O(h)

// dfs
function deepMerge(obj1: any, obj2: any): any {
    if (obj1 === null ||
        obj2 === null ||
        typeof obj1 !== 'object' ||
        typeof obj1 !== typeof obj2 ||
        Array.isArray(obj1) !== Array.isArray(obj2)) {
        return obj2;
    }

    let result = Array.isArray(obj1) ? [] : {};
    Object.keys(obj1).forEach(key => {
        if (obj2[key] === undefined) {
            result[key] = obj1[key]; 
        } else {
            result[key] = deepMerge(obj1[key], obj2[key]);
        }
    });
    Object.keys(obj2).forEach(key => obj1[key] === undefined ? result[key] = obj2[key] : null);
    return result;
};
