// Time:  O(n)
// Space: O(1)

function createObject(keysArr: any[], valuesArr: any[]): Record<string, any> {
    let result: Record<string, any> = {};
    keysArr.forEach((key, index) => {
        if (result[key] === undefined) {
            result[key] = valuesArr[index];
        }
    });
    return result;
};
