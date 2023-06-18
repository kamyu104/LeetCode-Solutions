// Time:  O(1)
// Space: O(1)

// promise
async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    return new Promise(resolve => {
        let result = 0, cnt = 0;
        const fn = (x: number) => {
            result += x;
            cnt++;
            if (cnt == 2) {
                resolve(result);
            }
        };
        promise1.then(fn);
        promise2.then(fn);
    });
};

// Time:  O(1)
// Space: O(1)
// promise
async function addTwoPromises2(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    return Promise.all([promise1, promise2]).then(([a, b]) => a+b);
};
