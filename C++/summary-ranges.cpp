// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) {
            return ranges;
        }

        int start = nums[0], end = nums[0];
        for (const auto& num : nums) {
            if (num > end + 1) {
                add_range(start, end, &ranges);
                start = end = num;
            } else {
                end = num;
            }
            if (num == nums.back()) {
                add_range(start, end, &ranges);
            }
        }

        return ranges;
    }
    
    void add_range(const int start, const int end,
                   vector<string> *ranges) {
        if (start != end) {
            ranges->emplace_back(to_string(start) + "->" + to_string(end));
        } else {
            ranges->emplace_back(to_string(start));
        }
    }
};
