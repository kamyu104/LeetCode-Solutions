// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> result(size(nums));
        for (const auto& x : nums) {
            if (x > 0) {
                result[pos] = x;
                pos += 2;
            } else {
                result[neg] = x;
                neg += 2;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// array, implementation
class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (nums[i] > 0) {
                pos.emplace_back(nums[i]);
            } else {
                neg.emplace_back(nums[i]);
            }
        }
        vector<int> result;
        for (int i = 0; i < size(nums); ++i) {
            if (i % 2 == 0) {
                result.emplace_back(pos.back()); pos.pop_back();
            } else {
                result.emplace_back(neg.back()); neg.pop_back();
            }
        }
        return result;
    }
};
