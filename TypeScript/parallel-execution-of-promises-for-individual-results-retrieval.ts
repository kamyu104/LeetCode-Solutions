// Time:  O(n)
// Space: O(n)

// promise
type FulfilledObj = {
    status: 'fulfilled';
    value: string;
}
type RejectedObj = {
    status: 'rejected';
    reason: string;
}
type Obj = FulfilledObj | RejectedObj;

function promiseAllSettled(functions: Function[]): Promise<Obj[]> {
    return new Promise((resolve, _) => {
        const result: Obj[] = [];
        let cnt = 0;
        functions.forEach((fn, i) => {
            fn()
                .then((res) => {
                    result[i] = {
                        status: 'fulfilled',
                        value: res
                    };
                })
                .catch((err) => {
                    result[i] = {
                        status: 'rejected',
                        reason: err
                    };
                })
                .finally(() => {
                    if (++cnt === functions.length) {
                        resolve(result);
                    }
                });
        });
    });
};
