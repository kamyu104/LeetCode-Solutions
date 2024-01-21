// Time:  O(nlogd)
// Space: O(d)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// sliding window, ordered set
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        for (int i = 1; i < 1 + (1 + dist); ++i) {
            os.insert({nums[i], i});
        }
        int64_t curr = 0;
        auto it = cbegin(os);
        for (int i = 0; i < k - 1; ++i, ++it) {
            curr += it->first;
        }
        int64_t mn = curr;
        for (int i = 1 + (1 + dist); i < size(nums); ++i) {
            os.insert({nums[i], i});
            curr += min(nums[i] - os.find_by_order(k - 1)->first, 0);
            curr -= min(nums[i - (1 + dist)] - os.find_by_order(k - 1)->first, 0);
            os.erase({nums[i - (1 + dist)], i - (1 + dist)});
            mn = min(mn, curr);
        }
        return nums[0] + mn;
    }
};

// Time:  O(nlogd)
// Space: O(d)
// faster but verbose
// sliding window, bst
class Solution2 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        multiset<int> bst1, bst2;
        int64_t curr = 0, mn = INF;
        for (int i = 1; i < size(nums); ++i) {
            bst1.emplace(nums[i]);
            curr += nums[i];
            if (size(bst1) > k - 1) {
                curr -= *rbegin(bst1);
                bst2.emplace(*rbegin(bst1));
                bst1.erase(prev(end(bst1)));
            }
            if (size(bst1) + size(bst2) > 1 + dist) {
                if (*cbegin(bst2) <= nums[i - (1 + dist)]) {
                    bst2.erase(bst2.find(nums[i - (1 + dist)]));
                } else {
                    bst1.erase(bst1.find(nums[i - (1 + dist)]));
                    curr -= nums[i - (1 + dist)] - *cbegin(bst2);
                    bst1.emplace(*cbegin(bst2));
                    bst2.erase(begin(bst2));
                }
            }
            if (size(bst1) == k - 1) {
                mn = min(mn, curr);
            }
        }
        return nums[0] + mn;
    }
};

// Time:  O(nlogd)
// Space: O(d)
// even faster but much more verbose
// sliding window, heap
class Solution3 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int total1 = 0, total2 = 0;
        int64_t curr = 0, mn = INF;
        for (int i = 1; i < size(nums); ++i) {
            max_heap.emplace(nums[i], -i);
            curr += nums[i];
            if (size(max_heap) - total1 > k - 1) {
                while (-max_heap.top().second < i - (1 + dist)) {
                    max_heap.pop();
                    --total1;
                }
                const auto [x, idx] = max_heap.top(); max_heap.pop();
                curr -= x;
                min_heap.emplace(x, idx);
            }
            if ((size(max_heap) - total1) + (size(min_heap) - total2) > 1 + dist) {
                while (-min_heap.top().second < i - (1 + dist)) {
                    min_heap.pop();
                    --total2;
                }
                if (min_heap.top() <= pair(nums[i - (1 + dist)], -(i - (1 + dist)))) {
                    ++total2;
                } else {
                    ++total1;
                    curr -= nums[i - (1 + dist)] - min_heap.top().first;
                    max_heap.emplace(min_heap.top()); min_heap.pop();
                }
            }
            if (size(max_heap) - total1 == k - 1) {
                mn = min(mn, curr);
            }
        }
        return nums[0] + mn;
    }
};

// Time:  O(nlogd)
// Space: O(d)
// even faster but much more verbose
// sliding window, heap
class Solution4 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> cnt1, cnt2;
        int total1 = 0, total2 = 0;
        int64_t curr = 0, mn = INF;
        for (int i = 1; i < size(nums); ++i) {
            max_heap.emplace(nums[i]);
            curr += nums[i];
            if (size(max_heap) - total1 > k - 1) {
                while (cnt1.count(max_heap.top())) {
                    const int x = max_heap.top(); max_heap.pop();
                    if (--cnt1[x] == 0) {
                        cnt1.erase(x);
                    }
                    --total1;
                }
                const int x = max_heap.top(); max_heap.pop();
                curr -= x;
                min_heap.emplace(x);
                
            }
            if ((size(max_heap) - total1) + (size(min_heap) - total2) > 1 + dist) {
                while (cnt2.count(min_heap.top())) {
                    const int x = min_heap.top(); min_heap.pop();
                    if (--cnt2[x] == 0) {
                        cnt2.erase(x);
                    }
                    --total2;
                }
                if (min_heap.top() <= nums[i - (1 + dist)]) {
                    ++cnt2[nums[i - (1 + dist)]];
                    ++total2;
                } else {
                    ++cnt1[nums[i - (1 + dist)]];
                    ++total1;
                    curr -= nums[i - (1 + dist)] - min_heap.top();
                    max_heap.emplace(min_heap.top()); min_heap.pop();
                }
            }
            if (size(max_heap) - total1 == k - 1) {
                mn = min(mn, curr);
            }
        }
        return nums[0] + mn;
    }
};
