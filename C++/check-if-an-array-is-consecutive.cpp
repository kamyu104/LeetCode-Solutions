// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        return (*max_element(cbegin(nums), cend(nums)) -
                *min_element(cbegin(nums), cend(nums)) + 1) == size(nums) &&
               size(nums) == size(unordered_set<int>(cbegin(nums), cend(nums)));
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    bool isConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] + 1 != nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
