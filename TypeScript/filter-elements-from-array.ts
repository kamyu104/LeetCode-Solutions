// Time:  O(n)
// Space: O(1)

function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let result = [];
    arr.forEach((x, i) => {
        if (fn(x, i)) {
           result.push(x);
        }
    });
    return result;
};
