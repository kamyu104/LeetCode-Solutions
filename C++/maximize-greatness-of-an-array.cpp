// Time:  O(n)
// Space: O(n)

// freq table, contructive algorithms
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        return size(nums) - max_element(cbegin(cnt), cend(cnt), [](const auto& x, const auto& y) {
            return x.second < y.second;
        })->second;
    }
};

// Time:  O(n)
// Space: O(n)
// sort, greedy, two pointers
class Solution2 {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int left = 0;
        for (int right = 0; right < size(nums); ++right) {
            if (nums[right] > nums[left]) {
                ++left;
            }
        }
        return left;
    }
};

