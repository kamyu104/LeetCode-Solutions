// Time:  O(n)
// Space: O(1)

function createObject(keysArr: any[], valuesArr: any[]): Record<string, any> {
    let obj: Record<string, any> = {};
    keysArr.forEach((key, index) => {
        if (obj[key] === undefined) {
            obj[key] = valuesArr[index];
        }
    });
    return obj;
};
