// Time:  O(n + klogk), k is the distinct number of chagned
// Space: O(k)

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (size(changed) % 2) {
            return {};
        }
        unordered_map<int, int> cnts;
        for (const auto& x : changed) {
            ++cnts[x];
        }
        vector<int> nums;
        for (const auto& [x, _] : cnts) {
            nums.emplace_back(x);
        }
        sort(begin(nums), end(nums));
        vector<int> result;
        for (const auto& x : nums) {
            if (cnts[x] > cnts[2 * x]) {
                return {};
            }
            for (int i = 0; i < cnts[x]; ++i, --cnts[2 * x]) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
