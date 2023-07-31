// Time:  O(n * t)
// Space: O(n * t)

declare global {
    interface String {
        replicate(times: number): string;
    }
}

// string
String.prototype.replicate = function(times: number) {
    let result = "";
    for (let curr = this; times !== 0; times >>= 1) {
        if (times & 1) {
            result += curr;
        }
        curr += curr;
    }
    return result;
}

// Time:  O(n * t)
// Space: O(n * t)
// string
String.prototype.replicate = function(times: number) {
    return new Array(times).fill(this).join('');
}
