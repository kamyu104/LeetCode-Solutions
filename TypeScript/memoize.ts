// Time:  O(1)
// Space: O(1)

type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    const lookup = {};
    return (...args) => {
        if (lookup[args] !== undefined) {
            return lookup[args];
        }
        lookup[args] = fn(...args);
        return lookup[args];
    }
}
