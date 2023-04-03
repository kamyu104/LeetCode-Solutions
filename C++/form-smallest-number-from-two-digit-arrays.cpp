// Time:  O(m + n)
// Space: O(m + n)

// hash table
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        static const int INF = numeric_limits<int>::max();

        int mn = INF;
        unordered_set<int> lookup(cbegin(nums1), cend(nums1));
        for (const auto& x : nums2) {
            if (lookup.count(x)) {
                mn = min(mn, x);
            }
        }
        if (mn != INF) {
            return mn;
        }
        int mn1 = *min_element(cbegin(nums1), cend(nums1));
        int mn2 = *min_element(cbegin(nums2), cend(nums2));
        if (mn1 > mn2) {
            swap(mn1, mn2);
        }
        return 10 * mn1 + mn2;
    }
};
