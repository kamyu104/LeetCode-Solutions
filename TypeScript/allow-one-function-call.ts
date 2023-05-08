// Time:  O(1)
// Space: O(1)

function once<T extends (...args: any[]) => any>(fn: T): 
((...args: Parameters<T>) => ReturnType<T> | undefined) {
    let called = false;
    return function (...args) {
        if (called) {
            return undefined;
        }
        called = true;
        return fn(...args);
    };
}
