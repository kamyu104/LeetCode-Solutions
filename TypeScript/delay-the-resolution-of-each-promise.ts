// Time:  O(1)
// Space: O(1)

// promise
function delayAll(functions: Function[], ms: number): Function[] {
    return functions.map(fn => {
        return async () => {
            await new Promise(resolve => setTimeout(resolve, ms));
            try {
                const result = await fn();
                return Promise.resolve(result);
            } catch (err) {
                return Promise.reject(err);
            }
        }
    });
};
