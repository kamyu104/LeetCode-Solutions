// Time:  valueOf:  O(n)
//        toString: O(n)
// Space: O(1)

class ArrayWrapper {
    #arr: number[];
    constructor(nums: number[]) {
        this.#arr = nums;
    }

    valueOf() {
        return this.#arr.reduce((total, x) => total+x, 0);
    }

    toString() {
        return '[' + this.#arr.join(',') + ']';
    }
};
