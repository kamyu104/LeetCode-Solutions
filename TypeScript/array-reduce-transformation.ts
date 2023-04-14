// Time:  O(n)
// Space: O(1)

type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    if (nums.length) {
        nums.forEach(num => init = fn(init, num));
    }
    return init;
};
