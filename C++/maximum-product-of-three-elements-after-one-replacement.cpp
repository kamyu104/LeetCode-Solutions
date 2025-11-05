// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        static const int L = 2;

        vector<int> top(L);
        for (auto x : nums) {
            x = abs(x);
            for (auto& y: top) {
                if (x > y) {
                    swap(x, y);
                }
            }
        }
        return 1e5 * top[0] * top[1];
    }
};
