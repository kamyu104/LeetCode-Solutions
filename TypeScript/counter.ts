// Time:  O(1)
// Space: O(1)

function createCounter(n: number): () => number {
    return () => n++;
}
