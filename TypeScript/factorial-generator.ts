// Time:  O(n)
// Space: O(1)

// generator
function* factorial(n: number): Generator<number> {
    for (let i = Math.min(n, 1), result = 1; i <= n; result *= ++i) {
        yield result;
    }
};
