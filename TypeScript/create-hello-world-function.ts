// Time:  O(1)
// Space: O(1)

function createHelloWorld() {
    return function(...args): string {
        return "Hello World";
    };
};
