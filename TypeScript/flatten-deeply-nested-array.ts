// Time:  O(n)
// Space: O(h)

type MultiDimensionalArray = (number | MultiDimensionalArray)[];

// dfs
var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    let result = [];
    let dfs = (arr, n) => {
        for (const x of arr) {
            if (n === 0 || typeof x === 'number') {
                result.push(x);
                continue;
            }
            dfs(x, n - 1);
        }
    }

    dfs(arr, n);
    return result;
};
