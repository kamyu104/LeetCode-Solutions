// Time:  O(klogn)
// Space: O(1)

class Solution {
public:
    int superEggDrop(int K, int N) {
        int left = 1, right = N;
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (check(mid, K, N)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool check(int n, int K, int N) {
        // Each combinatin of n moves with k broken eggs could represent a unique F.
        // Thus, the range size of F that all cominations can cover 
        // is the sum of C(n, k), k = 1..K
        int total = 0, c = 1;
        for (int k = 1; k <= K; ++k) {
            c *= n - k + 1;
            c /= k;
            total += c;
            if (total >= N) {
                return true;
            }
        }
        return false;
    }
};
