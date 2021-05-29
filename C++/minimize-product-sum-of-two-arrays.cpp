// Time:  O(nlogn)
// Space: O(1)

// Same problem from https://codingcompetitions.withgoogle.com/codejam/round/00000000004330f6/0000000000432f33
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2), greater<int>());
        return inner_product(nums1, nums2);
    }

private:
    int inner_product(const vector<int>& vec1, const vector<int>& vec2) {
        int result = 0;
        for (int i = 0; i < size(vec1); ++i) {
            result += vec1[i] * vec2[i];
        }
        return result;
    }
};
