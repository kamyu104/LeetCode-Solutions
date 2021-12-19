// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int64_t result = 0;
        for (int64_t i = 0, l = 0; i < size(prices); ++i) {
            ++l;
            if (i + 1 == size(prices) || prices[i] - 1 != prices[i + 1]) {
                result += l * (l + 1) / 2;
                l = 0;
            }
        }
        return result;
    }
};
