// Time:  O(logn)
// Space: O(1)

declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

// binary search
Array.prototype.upperBound = function(target: number) {
    const check = (x: number) => {
        return this[x] > target;
    };

    let left = 0, right = this.length-1;
    while (left <= right) {
        const mid = left+((right-left)>>1);
        if (check(mid)) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return left-1 >= 0 && this[left-1] === target? left-1 : -1;
};
