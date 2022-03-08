// Time:  O(nlogm + nlogn), m is the max of nums
// Space: O(n)

// sort
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const auto& transform = [&mapping](int x) {
            if (!x) {
                return mapping[x];
            }
            int result = 0;
            for (int base = 1; x; x /= 10, base *= 10) {
                result += mapping[x % 10] * base;
            }
            return result;
        };

        vector<pair<int, int>> order;
        for (int i = 0; i < size(nums); ++i) {
            order.emplace_back(transform(nums[i]), i);
        }
        sort(begin(order), end(order));
        vector<int> result;
        for (const auto& [_, i] : order) {
            result.emplace_back(nums[i]);
        }
        return result;
    }
};
