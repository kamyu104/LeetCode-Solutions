// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const auto& find_top1_and_top2 = [](const auto& cnt) {
            int top1 = -1, top2 = -1;
            for (const auto& [k, v] : cnt) {
                if (top1 == -1 || v >= cnt.at(top1)) {
                    top2 = top1;
                    top1 = k;
                } else if (top2 == -1 || v > cnt.at(top2)) {
                    top2 = k;
                }
            }
            return make_pair(top1, top2);
        };

        unordered_map<int, int> even;
        for (int i = 0; i < size(nums); i += 2) {
            ++even[nums[i]];
        }
        unordered_map<int, int> odd;
        for (int i = 1; i < size(nums); i += 2) {
            ++odd[nums[i]];
        }
        const auto& [even_top1, even_top2] = find_top1_and_top2(even);
        const auto& [odd_top1, odd_top2] = find_top1_and_top2(odd);
        if (even_top1 != odd_top1) {
            return size(nums) - even[even_top1] - (odd_top1 != -1 ? odd[odd_top1] : 0);
        }
        return min(size(nums) - even[even_top1] - (odd_top2 != -1 ? odd[odd_top2] : 0),
                   size(nums) - odd[odd_top1] - (even_top2 != -1 ? even[even_top2] : 0));
    }
};
