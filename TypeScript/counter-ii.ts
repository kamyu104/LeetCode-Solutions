// Time:  ctor:      O(1)
//        increment: O(1)
//        decrement: O(1)
//        reset:     O(1)
// Space: O(1)

// design
class Counter {
    init: number;
    curr: number;
    constructor(init: number) {
        this.curr = this.init = init;
    }

    increment() {
        return ++this.curr;
    }

    decrement() {
        return --this.curr;
    }

    reset() {
        return this.curr = this.init;
    }
};

function createCounter(init: number) {
    return new Counter(init);
};
