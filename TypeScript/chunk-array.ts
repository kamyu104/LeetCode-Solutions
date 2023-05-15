// Time:  O(n)
// Space: O(1)

function chunk(arr: any[], size: number): any[][] {
    let result = [];
    for (let i = 0; i < arr.length; i += size) {
        result.push(arr.slice(i, i + size));
    }
    return result;
};
