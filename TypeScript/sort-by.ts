// Time:  O(nlogn)
// Space: O(1)

// sort
function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a)-fn(b));
};
