// Time:  O(l * n)
// Space: O(n)

// greedy, bitmasks, sort
class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        static const int L = 15;

        vector<int> result(L);
        vector<vector<int>> groups = {nums};
        for (int i = L - 1; i >= 0; --i) {
            int prefix = 0;
            for (int j = 0; j < size(groups); ++j) {
                vector<int> ones;
                for (const auto& x : groups[j]) {
                    if (x & (1 << i)) {
                        ones.emplace_back(x);
                    }
                }
                prefix += size(ones);
                if (size(ones) != size(groups[j])) {
                    if (!empty(ones)) {
                        vector<int> zeros;
                        for (const auto& x : groups[j]) {
                            if (!(x & (1 << i))) {
                                zeros.emplace_back(x);
                            }
                        }
                        groups[j] = ones;
                        groups.emplace(begin(groups) + (j + 1), zeros);
                    }
                    break;
                }
            }
            result[(L - 1) - i] = prefix;
        }
        return result;
    }
};
