// Time:  O(n)
// Space: O(n)

// math, hash table, greedy
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> lookup1(cbegin(nums1), cend(nums1));
        unordered_set<int> lookup2(cbegin(nums2), cend(nums2));
        unordered_set<int> common;
        for (const auto& x : lookup1) {
            if (lookup2.count(x)) {
                common.emplace(x);
            }
        }
        const int n = size(nums1);
        const int n1 = size(lookup1);
        const int n2 = size(lookup2);
        const int c = size(common);
        return min(min(n1 - c, n / 2) + min(n2 - c, n / 2) + c, n);
    }
};

// Time:  O(n)
// Space: O(n)
// math, hash table, greedy
class Solution2 {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> lookup1(cbegin(nums1), cend(nums1));
        unordered_set<int> lookup2(cbegin(nums2), cend(nums2));
        unordered_set<int> common;
        for (const auto& x : lookup1) {
            if (lookup2.count(x)) {
                common.emplace(x);
            }
        }
        const int n = size(nums1);
        const int n1 = size(lookup1);
        const int n2 = size(lookup2);
        const int c = size(common);
        const int r1 = max(n / 2 - (n1 - c), 0);
        const int r2 = max(n / 2 - (n2 - c), 0);
        return min(n1 - c, n / 2) + min(n2 - c, n / 2) + min(r1 + r2, c);
    }
};
