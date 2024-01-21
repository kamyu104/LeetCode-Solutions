// Time:  O(nlogd)
// Space: O(d)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// sliding window, ordered set
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        for (int i = 1; i < 1 + dist; ++i) {
            os.insert({nums[i], i});
        }
        int64_t curr = 0;
        auto it = cbegin(os);
        for (int i = 0; i < k - 2; ++i, ++it) {
            curr += it->first;
        }
        int64_t mn = INF;
        for (int i = 1 + dist; i < size(nums); ++i) {
            os.insert({nums[i], i});
            curr += min(nums[i], os.find_by_order(k - 2)->first);
            mn = min(mn, curr);
            curr -= min(nums[i - dist], os.find_by_order(k - 2)->first);
            os.erase({nums[i - dist], i - dist});
        }
        return nums[0] + mn;
    }
};
