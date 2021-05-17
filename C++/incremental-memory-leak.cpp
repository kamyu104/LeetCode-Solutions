// Time:  O(1)
// Space: O(1)

// Same problem from https://codingcompetitions.withgoogle.com/codejam/round/000000000019ffb9/00000000003384ea
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        bool is_swapped = false;
        if (memory1 < memory2) {
            swap(memory1, memory2);
            is_swapped = true;
        }
        int n = f(1, 1, memory1 - memory2);
        memory1 -= s(1, 1, n);
        if (memory1 == memory2) {
            is_swapped = false;
        }
        int l = f(n + 1, 2, memory1);
        int r = f(n + 2, 2, memory2);
        memory1 -= s(n + 1, 2, l);
        memory2 -= s(n + 2, 2, r);
        if (is_swapped) {
            swap(memory1, memory2);
        }
        return {n + l + r + 1, memory1, memory2};
    }

private:
    int s(int a, int d, int n) {
        return (2LL * a + (n - 1) * d) * n / 2;
    }

    int f(int a, int d, int x) {
        int r = (-(2LL * a - d) + sqrt((2LL * a - d) * (2LL * a - d) + 8LL * d * x)) / (2 * d);
        if (s(a, d, r) > x) {  // adjust float accuracy
            --r;
        }
        return r;
    }
};
