// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right;
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            if (left.count(nums[i]) == 0) {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
            ++counts[nums[i]];
        }
        auto degree = max_element(counts.begin(), counts.end(),
                                  [](const pair<int, int>& a,
                                     const pair<int, int>& b) {
                                      return a.second < b.second;
                                  })->second;
        auto result = numeric_limits<int>::max();
        for (const auto& kvp : counts) {
            if (kvp.second == degree) {
                result = min(result, right[kvp.first] - left[kvp.first] + 1);
            }
        }
        return result;
    }
};
