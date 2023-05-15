// Time:  O(1)
// Space: O(1)

type F = (...args: any[]) => void

function throttle(fn: F, t: number): F {
    let pending = false;
    let nxtArgs;
    const wrapper = (...args) => {
        nxtArgs = args;
        if (pending) {
            return;
        }
        pending = true;
        nxtArgs = undefined;
        fn(...args);
        setTimeout(() => {
            pending = false;
            if (nxtArgs) {
                wrapper(...nxtArgs);
            }
        }, t);
    }
    return wrapper;
};
