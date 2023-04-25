// Time:  O(t)
// Space: O(1)

function cancellable<T>(generator: Generator<Promise<any>, T, unknown>): [() => void, Promise<T>] {
    let cancel;
    const cancelPromise = new Promise((_, reject) => {
        cancel = () => reject("Cancelled");
    });
    cancelPromise.catch(() => {});
    const promise = (async() => {
        let next = generator.next();
        while (!next.done) {
            try {
                next = generator.next(await Promise.race([next.value, cancelPromise]));
            } catch (e) {
                next = generator.throw(e);
            }
        }
        return next.value;
    })();

    return [cancel, promise];
};
