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
                const auto& pos = lookup[nums[right]];
                if (pos.back() == right) {
                    ++d;
                    if (size(pos) < d) {
                        break;
                    }
                    if (size(pos) >= d + 1) {
                        r = min(r, pos[size(pos) - 1 - d]);
                    }
                    l = max(l, pos[size(pos) - d]);
                }
                result += l <= right;
                ++right;
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// brute force, freq table, hash table
class Solution2 {
public:
    int countStaircase(vector<int>& nums) {
        int result = 0;
        for (int left = 0; left < size(nums); ++left) {
            unordered_map<int, int> cnt, rank;
            int d = 0, bal = 0;
            for (int right = left; right < size(nums); ++right) {
                if (!cnt.count(nums[right])) {
                    ++d;
                    rank[nums[right]] = d;
                    cnt[nums[right]] = 1;
                    bal += d - 1;
                } else {
                    ++cnt[nums[right]];
                    --bal;
                    if (cnt[nums[right]] > rank[nums[right]]) {
                        break;
                    }
                }
                if (bal == 0) {
                    ++result;
                }
            }
        }
        return result;
    }
};
