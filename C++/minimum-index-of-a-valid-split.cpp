// Time:  O(n)
// Space: O(1)

// Boyer–Moore majority vote algorithm, linear search
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const auto& boyer_moore_majority_vote = [&]() {
            int m = nums[0], cnt = 1;
            for (int i = 1; i < size(nums); ++i) {
                if (m == nums[i]) {
                    ++cnt;
                } else {
                    --cnt;
                    if (cnt == 0) {
                        m = nums[i];
                        cnt = 1;
                    }
                }
            }
            return m;
        };

        const auto& m = boyer_moore_majority_vote();
        const auto& total = count(cbegin(nums), cend(nums), m);
        for (int i = 0, cnt = 0; i < size(nums); ++i) {
            if (nums[i] == m) {
                ++cnt;
            }
            if (cnt * 2 > i + 1 && (total - cnt) * 2 > size(nums) - (i + 1)) {
                return i;
            }
        }
        return -1;
    }
};
