// Time:  O(1)
// Space: O(1)

// generator
function* cycleGenerator(arr: number[], startIndex: number): Generator<number, void, number> {
    let i = startIndex;
    while (true) {
        const jump = yield arr[i]
        i = ((i+jump) % arr.length + arr.length) % arr.length;
    }
};
