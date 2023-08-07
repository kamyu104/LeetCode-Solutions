// Time:  O(1)
// Space: O(1)

let id = 0;
const lookup = new Map();

function customInterval(fn: Function, delay: number, period: number): number {
    const fn1 = () => {
        lookup.set(i, setTimeout(fn2, curr));
        curr += period;
    };
    const fn2 = () => {
        fn();
        fn1();
    };
    let i = id++;
    let curr = delay;
    fn1();
    return i;
}

function customClearInterval(id: number) {
    clearTimeout(lookup.get(id));
    lookup.delete(id); 
}
