// Time:  O(nlogk)
// Space: O(k)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered set, two pointers
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> result;
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        for (int i = 0; i < size(nums); ++i) {
            if (i - k >= 0) {
                os.erase(pair(nums[i - k], i - k));
            }
            os.insert({nums[i], i});
            if (i - k + 1 >= 0) {
                result.emplace_back(min(os.find_by_order(x - 1)->first, 0));
            }
        }
        return result;
    }
};
