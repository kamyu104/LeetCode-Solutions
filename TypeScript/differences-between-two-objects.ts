// Time:  O(n)
// Space: O(h)

// dfs
function objDiff(obj1: any, obj2: any): any {
    let result = {};
    for (const [k, o1] of Object.entries(obj1)) {
        if (!(k in obj2)) {
            continue;
        }
        const o2 = obj2[k];
        if (typeof o1 === 'object' && typeof o2 === 'object' && Array.isArray(o1) === Array.isArray(o2)) {
            result[k] = objDiff(o1, o2);
            if (Object.keys(result[k]).length === 0) {
                delete result[k];
            }
        } else if (o1 !== o2) {
            result[k] = [o1, o2];
        }
    }
    return result;
};
