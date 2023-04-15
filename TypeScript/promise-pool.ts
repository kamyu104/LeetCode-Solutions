// Time:  O(c + n / c)
// Space: O(c)

type F = () => Promise<any>;

function promisePool(functions: F[], n: number): Promise<any> {
    const nxt = () => functions[n++]?.().then(nxt);
    return Promise.all(functions.slice(0, n).map(fn => fn().then(nxt)));
};
