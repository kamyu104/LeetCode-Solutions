// Time:  O(n)
// Space: O(1)

function invertObject(obj: Record<any, any>): Record<any, any> {
    let result = {};
    for (let [k, v] of Object.entries(obj)) {
        if (!(v in result)) {
            result[v] = k;
        } else if (!Array.isArray(result[v])) {
            result[v] = [result[v], k];
        } else {
            result[v].push(k);
        }
    }
    return result;
};
