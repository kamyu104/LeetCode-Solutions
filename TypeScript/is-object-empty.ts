// Time:  O(1)
// Space: O(1)

function isEmpty(obj: Record<string, any> | any[]): boolean {
    return Array.isArray(obj) ? obj.length === 0 : Object.keys(obj).length === 0; 
};
