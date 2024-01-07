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
        const int d1 = min(n1 - c, n / 2);
        const int d2 = min(n2 - c, n / 2);
        return min(n, d1 + d2 + c);
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
        const int d1 = min(n1 - c, n / 2);
        const int d2 = min(n2 - c, n / 2);
        const int r1 = n / 2 - d1;
        const int r2 = n / 2 - d2;
        return d1 + d2 + min(r1 + r2, c);  // = min(d1+d2+r1+r2, d1+d2+c) = min(d1+d2+(n//2-d1)+(n//2-d2), d1+d2+c) = min(n, d1+d2+c)
    }
};
