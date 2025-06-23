// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const auto& count = [&](int j) {
            int result = 0;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i] % 2) {
                    result += abs(j - i);
                    j += 2;
                }
            }
            return result;
        };

        const auto& cnt = accumulate(cbegin(nums), cend(nums), 0, [](const auto& accu, const auto& x) {
            return accu + x % 2;
        });
        if (cnt == size(nums) - cnt) {
            return min(count(0), count(1));
        }
        if (cnt == (size(nums) - cnt) + 1) {
            return count(0);
        }
        if (cnt + 1 == size(nums) - cnt) {
            return count(1);
        }
        return -1;
    }
};
