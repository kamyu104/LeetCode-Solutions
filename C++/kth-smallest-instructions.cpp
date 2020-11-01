// Time:  O((m + n)^2)
// Space: O(1)

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int r = destination[0], c = destination[1];
        string result;
        while (r + c) {
            int count = nCr(r + (c - 1), r);  // the number of HX..X combinations
            if (k <= count) {  // the kth instruction is one of HX..X combinations, so go right
                --c;
                result.push_back('H');
            } else {  // the kth instruction is one of VX..X combinations, so go down
                k -= count;  // the kth one of XX..X combinations is the (k-count)th one of VX..X combinations
                --r;
                result.push_back('V');
            }
        }
        return result;
    }

private:
    uint64_t nCr(int n, int r) {  // Time: O(n), Space: O(1)
        if (n < r) {
            return 0;
        }
        if (n - r < r) {
            return nCr(n, n - r);
        }
        uint64_t c = 1;
        for (int k = 1; k <= r; ++k) {
            c *= n - k + 1;
            c /= k;
        }
        return c;
    }
};
