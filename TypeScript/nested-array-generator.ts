// Time:  O(1)
// Space: O(d)

type MultidimensionalArray = (MultidimensionalArray | number)[]

// iterative dfs
function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    let stk : MultidimensionalArray = [arr];
    while (stk.length) {
        let x = stk.pop()
        if (Array.isArray(x)) {
            x.reduceRight((accu : MultidimensionalArray, curr) => (accu.push(curr), accu), stk);
        } else {
            yield x;
        }
    }
};

// Time:  O(1)
// Space: O(d)
// dfs
function* inorderTraversal2(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (let x of arr) {
        if (Array.isArray(x)) {
            yield* inorderTraversal(x);
        } else {
            yield x;
        }
    }
};
