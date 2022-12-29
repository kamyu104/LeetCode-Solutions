// Time:  O(nlogn)
// Space: O(n)

// heap
class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        vector<bool> right(size(nums));
        priority_queue<int> max_heap1;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (size(max_heap1) == k && nums[i] > max_heap1.top()) {
                right[i] = true;
            } 
            max_heap1.emplace(nums[i]);
            if (size(max_heap1) == k + 1) {
                max_heap1.pop();
            }
        }
        int result = 0;
        priority_queue<int> max_heap2;
        for (int i = 0; i < size(nums); ++i) {
            if (size(max_heap2) == k && nums[i] > max_heap2.top() && right[i]) {
                ++result;
            } 
            max_heap2.emplace(nums[i]);
            if (size(max_heap2) == k + 1) {
                max_heap2.pop();
            }
        }
        return result;
    }
};


// Time:  O(nlogn)
// Space: O(n)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// sorted set
class Solution2 {
public:
    int kBigIndices(vector<int>& nums, int k) {
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os1, os2;
        unordered_map<int, int> lookup;
        for (const auto& x : nums) {
            os2.insert({x, lookup[x]++});
        }
        int result = 0;
        for (const auto& x : nums) {
            os2.erase({x, --lookup[x]});  
            if (os1.order_of_key({x, 0}) >= k && os2.order_of_key({x, 0}) >= k) {
                ++result;
            }
            os1.insert({x, lookup[x]});
        }
        return result;
    }
};
