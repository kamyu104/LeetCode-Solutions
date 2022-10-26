// Time:  O(nlogn)
// Space: O(1)

// greedy, sort
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        const auto& cmp = [](const auto& a, const auto& b) {
            return pair(a % 2, a) < pair(b % 2, b);
        };

        sort(begin(nums), end(nums), cmp);
        sort(begin(target), end(target), cmp);
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += abs(nums[i] - target[i]) / 2;
        }
        return result / 2;
    }
};
