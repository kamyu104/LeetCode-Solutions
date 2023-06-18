// Time:  O(n)
// Space: O(n)

// promise
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise((resolve, reject) => {
        let result = new Array(functions.length);
        let cnt = 0;
        functions.forEach((fn, i) => {
            fn()
                .then(res => {
                    result[i] = res;
                    if (++cnt === functions.length) {
                        resolve(result);
                    }
                })
                .catch(err => reject(err));
        });
    });
};
