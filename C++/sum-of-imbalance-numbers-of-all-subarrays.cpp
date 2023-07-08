// Time:  O(n)
// Space: O(n)

// hash table, combinatorics
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        vector<int> right(size(nums), size(nums));
        vector<int> lookup((size(nums) + 1) + 1, size(nums));
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = min(lookup[nums[i]], lookup[nums[i] + 1]);  // to avoid duplicated count
            lookup[nums[i]] = i;
        }
        int result = 0, left = 0;
        lookup.assign((size(nums) + 1) + 1, -1);
        for (int i = 0; i < size(nums); ++i) {
            left = lookup[nums[i] + 1];
            lookup[nums[i]] = i;
            result += (i - left) * (right[i] - i);
        }
        return result - (size(nums) + 1) * size(nums) / 2;  // since we overcount 1 in each subarray, we have to subtract all of them
    }
};

// Time:  O(n^2)
// Space: O(n)
// hash table, two pointers
class Solution2 {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int result = 0;
        for (int right = 0; right < size(nums); ++right) {
            unordered_set<int> lookup = {nums[right]};
            int curr = 0;
            for (int left = right - 1; left >= 0; --left) {
                if (!lookup.count(nums[left])) {
                    lookup.emplace(nums[left]);
                    curr += 1 - lookup.count(nums[left] - 1) - lookup.count(nums[left] + 1);
                }
                result += curr;
            }
        }
        return result;
    }
};
