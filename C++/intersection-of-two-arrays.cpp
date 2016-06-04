// Time:  O(m + n)
// Space: O(min(m, n))

// Hash solution.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_set<int> lookup{nums1.cbegin(), nums1.cend()};

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup.count(i)) {
                result.emplace_back(i);
                lookup.erase(i);
            }
        }

        return result;
    }
};


// Time:  O(max(m, n) * log(max(m, n)))
// Space: O(1)
// Two pointers solution.
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
        while (it1 != nums1.cend() && it2 != nums2.cend()) {
            if (*it1 < *it2) {
                ++it1;
            } else if (*it1 > *it2) {
                ++it2;
            } else {
                if (result.empty() || result.back() != *it1) {
                    result.emplace_back(*it1);
                }
                ++it1, ++it2;
            }
        }
        return result;
    }
};
