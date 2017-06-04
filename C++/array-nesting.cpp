// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        auto result = 0;
        for (const auto& num : nums) {
            if (num != numeric_limits<int>::max()) {
                auto start = num, count = 0;
                while (nums[start] != numeric_limits<int>::max()) {
                    auto temp = start;
                    start = nums[start];
                    nums[temp] = numeric_limits<int>::max();
                    ++count;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};
