// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        for (const auto& x : nums) {
            if (x % 2 == 0 && cnt[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
