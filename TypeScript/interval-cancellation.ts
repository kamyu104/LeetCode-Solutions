// Time:  O(1)
// Space: O(1)

function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    const tid = setInterval(() => fn(...args), t);
    return () => clearInterval(tid);
};
