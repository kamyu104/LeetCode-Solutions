// Time:  O(n + m), m is the max number of nums
// Space: O(m)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const auto& m = *max_element(cbegin(nums), cend(nums));
        auto count = counter(nums);
        for (int i = 0; i <= m; ++i) {
            count[i] += count[i - 1];
        }
        vector<int> result;
        for (const auto& i : nums) {
            result.emplace_back(count[i - 1]);
        }
        return result;
    }

private:
    unordered_map<int, int> counter(const vector<int>& nums) const {
        unordered_map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        return count;
    }
};
