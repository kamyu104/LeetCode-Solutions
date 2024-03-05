// Time:  O(nlogn)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered set
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os1, os2;
        os1.insert({nums[0], 0});
        os2.insert({nums[1], 1});
        vector<int> a = {nums[0]}, b = {nums[1]};
        for (int i = 2; i < size(nums); ++i) {
            const int cnt1 = size(os1) - os1.order_of_key({nums[i] + 1, 0});
            const int cnt2 = size(os2) - os2.order_of_key({nums[i] + 1, 0});
            if (cnt1 > cnt2 || (cnt1 == cnt2 && size(a) <= size(b))) {
                os1.insert({nums[i], i});
                a.emplace_back(nums[i]);
            } else {
                os2.insert({nums[i], i});
                b.emplace_back(nums[i]);
            }
        }
        a.insert(end(a), cbegin(b), cend(b));
        return a;
    }
};
