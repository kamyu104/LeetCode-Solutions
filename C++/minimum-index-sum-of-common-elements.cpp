// Time:  O(n + m)
// Space: O(n)

// hash table
class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();

        unordered_map<int, int> lookup;
        for (int i = 0; i < size(nums1); ++i) {
            if (lookup.count(nums1[i])) {
                continue;
            }
            lookup[nums1[i]] = i;
        }
        int result = INF;
        for (int j = 0; j < size(nums2); ++j) {
            if (lookup.count(nums2[j])) {
                result = min(result, lookup[nums2[j]] + j);
            }
        }
        return result != INF ? result : -1;
    }
};
