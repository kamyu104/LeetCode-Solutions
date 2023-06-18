// Time:  O(mlogm + nlogn)
// Space: O(1)

// sort, two pointers
function join(arr1: any[], arr2: any[]): any[] {
    arr1.sort((a, b) => a.id-b.id);
    arr2.sort((a, b) => a.id-b.id);
    let i = 0, j = 0;
    let result = [];
    while (i < arr1.length || j < arr2.length) {
        if (j === arr2.length || (i < arr1.length && arr1[i].id < arr2[j].id)) {
            result.push(arr1[i++]);
        } else if (i === arr1.length || (j < arr2.length && arr2[j].id < arr1[i].id)) {
            result.push(arr2[j++]);
        } else {
            result.push({...arr1[i++], ...arr2[j++]});
        }
    }
    return result;
};
