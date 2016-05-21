// If the given array is not sorted and the memory is unlimited:
//   - Time:  O(m + n)
//   - Space: O(min(m, n))
// elif the given array is already sorted:
//   if the memory is unlimited, and (m << n or m >> n)
//     - Time:  O(min(m, n) * log(max(m, n)))
//     - Space: O(min(m, n))
//   else:
//     - Time:  O(m + n)
//     - Soace: O(1)
// elif the memory is limited:
//     - Time:  O(max(m, n) * log(max(m, n)))
//     - Space: O(max(m, n))

# If the given array is not sorted and the memory is unlimited.
# Time:  O(m + n)
# Space: O(min(m, n))
# Hash solution.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> lookup;
        for (const auto& i : nums1) {
            ++lookup[i];
        }

        vector<int> result;
        for (const auto& i : nums2) {
            if (lookup[i] > 0) {
                result.emplace_back(i);
                --lookup[i];
            }
        }

        return result;
    }
};

