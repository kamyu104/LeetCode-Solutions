// Time:  O(n * sqrt(r)), r = max(nums)
// Space: O(sqrt(r))

// number theory
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        const auto& factorize = [](int x) {
            vector<pair<int, int>> result;
            for (int d = 2; d * d <= x; d += (d == 2) ? 1: 2) {
                int e = 0;
                for (; x % d == 0; ++e) {
                    x /= d;
                }
                if (e) {
                    result.emplace_back(d, e);
                }
            }
            if (x > 1) {
                result.emplace_back(x, 1);
            }
            return result;
        };

        unordered_map<int, int> right;
        for (const auto& x : nums) {
            for (const auto& [p, c] : factorize(x)) {
                right[p] += c;
            }
        }
        unordered_map<int, int> left;
        for (int i = 0, cnt = 0; i < size(nums) - 1; ++i) {
            for (const auto& [p, c] : factorize(nums[i])) {
                if (!left[p]) {
                    ++cnt;
                }
                left[p] += c;
                right[p] -= c;
                if (!right[p]) {
                    --cnt;
                }
                if (!cnt) {
                    return i;
                }
            }
        }
        return -1;
    }
};
