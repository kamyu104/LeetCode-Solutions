// Time:  O(1)
// Space: O(1)

type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
    return async function(...args) {
        return Promise.race([
            fn.apply(this, args),
            new Promise((_, reject) => setTimeout(() => reject('Time Limit Exceeded'), t)),
        ]);
    };
};
