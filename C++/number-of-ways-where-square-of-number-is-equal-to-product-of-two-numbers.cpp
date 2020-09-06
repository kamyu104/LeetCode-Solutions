// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        for (const auto& n : nums1) {
            result += twoProduct(nums2, static_cast<int64_t>(n) * n);
        }
        for (const auto& n : nums2) {
            result += twoProduct(nums1, static_cast<int64_t>(n) * n);
        }
        return result;
    }

private:
    int twoProduct(const vector<int>& nums, int64_t i) {
        unordered_map<int, int> lookup;
        int count = 0;
        for (const auto& num : nums) {
            if (i % num) {
                continue;
            }
            count += lookup[i / num];
            ++lookup[num];
        }
        return count;
    }  
};
