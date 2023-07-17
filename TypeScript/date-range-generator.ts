// Time:  O(1)
// Space: O(1)

// generator
function* dateRangeGenerator(start: string, end: string, step: number) : Generator<string> {
    const e = new Date(end);
    for (let d = new Date(start); d <= e; d.setDate(d.getDate() + step)) {
        yield d.toISOString().split('T')[0];
    }
};
