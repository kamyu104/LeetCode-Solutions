// Time:  O(n)
// Space: O(n)

function curry(fn: Function): Function {
    let result = [];
    return function curried(...args) {
        result.push(...args);
        if (result.length < fn.length) {
            return curried;
        }
        return fn(...result);
    };
};
