// Time:  O(1)
// Space: O(1)

// proxy
function createInfiniteObject(): Record<string, () => string> {
    return new Proxy({}, {
        get(_, prop) {
            return () => prop;
        }
    });
};
