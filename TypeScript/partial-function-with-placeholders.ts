// Time:  O(n)
// Space: O(n)

function partial(fn: Function, args: any[]): Function {
    return function(...restArgs) {
        return fn(...args.map(x => x === '_' ? restArgs.shift() : x).concat(restArgs));   
    }
};
