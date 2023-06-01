// Time:  O(n)
// Space: O(h)

type Obj = Record<any, any>;

// dfs
function compactObject(obj: Obj): Obj {
    if (obj === null) {
        return null;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    if (typeof obj !== "object") {
        return obj;
    }
    return Object.keys(obj).reduce(
        (accu, key) => {
            accu[key] = compactObject(obj[key]);
            if (!Boolean(accu[key])) {
                delete accu[key];
            }
            return accu;
        }, {});
};
