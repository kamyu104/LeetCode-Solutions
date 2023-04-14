// Time:  O(1)
// Space: O(1)

declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function() {
    return this[this.length - 1] ?? -1;
};
