// Time:  O(n * sqrt(n))
// Space: O(n)

// hash table
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int result = 0;
        unordered_map<int, vector<int>> lookup;
        for (int left = size(nums) - 1; left >= 0; --left) {
            lookup[nums[left]].emplace_back(left);
            for (int right = left, d = 0, l = -1, r = size(nums); right < r && l <= r;) {  // each right is visited by O(sqrt(n)) lefts
                const auto& idxs = lookup[nums[right]];
                if (idxs.back() == right) {
                    ++d;
                    if (size(idxs) < d) {
                        break;
                    }
                    if (size(idxs) >= d + 1) {
                        r = min(r, idxs[size(idxs) - 1 - d]);
                    }
                    l = max(l, idxs[size(idxs) - d]);
                }
                result += l <= right;
                ++right;
            }
        }
        return result;
    }
};
