// Time:  O(n)
// Space: O(n)

function twoSum(nums: number[], target: number): number[] {
    let lookup = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (lookup.has(target - nums[i])) {
            return [lookup.get(target - nums[i]), i];
        }
        lookup.set(nums[i], i);
    }
    return [];
};
