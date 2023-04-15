// Time:  O(n)
// Space: O(t)

type Fn = (...params: any) => any

// trie
function memoize(fn: Fn): Fn {
    let trie = new Map();
    return function (...args) {
        let curr = trie;
        for (const arg of args) {
            if (!curr.has(arg)) {
                curr.set(arg, new Map());
            }
            curr = curr.get(arg);
        }
        if (!curr.has("_end")) {
            curr.set("_end", fn(...args));
        }
        return curr.get("_end");
    }
}
