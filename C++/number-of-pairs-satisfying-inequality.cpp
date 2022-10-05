// Time:  O(nlogn)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered set, binary search
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        int64_t result = 0;
        for (int i = 0; i < size(nums1); ++i) {
            result += os.order_of_key({(nums1[i] - nums2[i]) + diff + 1, 0});
            os.insert({nums1[i] - nums2[i], i});
        }
        return result;
    }
};
