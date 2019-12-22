// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        for (const auto [num, c] : count) {
            if (!c) {
                continue;
            }
            for (int i = num; i < num + k; ++i) {
                if (count[i] < c) {
                    return false;
                }
                count[i] -= c;
            }
        }
        return true;
    }
};
