// Time:  O(n^2)
// Space: O(n)

// freq table
class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                if (cnt.count((nums[i] + nums[j]) % d)) {
                    result += cnt[(nums[i] + nums[j]) % d];
                }
            }
            ++cnt[(d + (-nums[i]) % d) % d];
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// freq table
class Solution2 {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            if (cnt.count(nums[i] % d)) {
                result += cnt[nums[i] % d];
            }
            for (int j = 0; j < i; ++j) {
                ++cnt[(d + -(nums[i] + nums[j]) % d) % d];
            }
        }
        return result;
    }
};
