// Time:  O(1)
// Space: O(!)

declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function() {
    return new Date(this.getTime() + 24 * 60 * 60 * 1000).toISOString().split("T")[0];
}
