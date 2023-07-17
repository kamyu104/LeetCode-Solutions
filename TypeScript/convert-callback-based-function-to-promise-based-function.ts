// Time:  O(1)
// Space: O(1)

type CallbackFn = (
    next: (data: number, error: string) => void, 
    ...args: number[]
) => void
type Promisified = (...args: number[]) => Promise<number>

// promise
function promisify(fn: CallbackFn): Promisified {
    return async function(...args) {
        return new Promise((resolve, reject) => {
            const cb = (val, err) => {
                err ? reject(err) : resolve(val);
            };
            fn(cb, ...args);
        });
    };
};
