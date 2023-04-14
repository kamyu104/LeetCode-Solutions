// Time:  O(n)
// Space: O(1)

function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let result = [];
    arr.forEach((x, i) => {
        result.push(fn(x, i));
    });
    return result;
};
