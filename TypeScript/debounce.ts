// Time:  O(1)
// Space: O(1)

type F = (...p: any[]) => any

function debounce(fn: F, t: number): F {
    let timeout = null;
    return (...args) => {
        clearTimeout(timeout);
        timeout = setTimeout(fn, t, ...args);
    }
};
