// Time:  O(nlogd)
// Space: O(d)

// fastest and less verbose
// sliding window, heap
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& get_top = [](auto& heap, auto& total, const int d) {
            while (-heap.top().second < d) {
                heap.pop();
                --total;
            }
            return heap.top();
        };

        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        int total1 = 0, total2 = 0;
        int64_t mn = INF, curr = 0;
        for (int i = 1; i < size(nums); ++i) {
            max_heap.emplace(nums[i], -i);
            curr += nums[i];
            if (i > k - 1) {
                const auto [x, idx] = get_top(max_heap, total1, i - (1 + dist)); max_heap.pop();
                curr -= x;
                min_heap.emplace(x, idx);
            }
            if (i > 1 + dist) {
                if (get_top(min_heap, total2, i - (1 + dist)) <= pair(nums[i - (1 + dist)], -(i - (1 + dist)))) {
                    lazy_delete(min_heap, total2, i - (1 + dist));
                } else {
                    lazy_delete(max_heap, total1, i - (1 + dist));                    
                    curr -= nums[i - (1 + dist)] - min_heap.top().first;
                    max_heap.emplace(min_heap.top()); min_heap.pop();
                }
            }
            if (i >= k - 1) {
                mn = min(mn, curr);
            }
        }
        return nums[0] + mn;
    }

private:
    template<typename T>
    void lazy_delete(T& heap, int& total, const int d) {
        ++total;
        if (total <= size(heap) - total) {
            return;
        }
        T new_heap;
        while (!empty(heap)) {
            const auto x = heap.top(); heap.pop();
            if (-x.second <= d) {
                --total;
                continue;
            }
            new_heap.emplace(x);
        }
        heap = move(new_heap);
    }
};

// Time:  O(nlogd)
// Space: O(d)
// faster but more verbose
// sliding window, heap, freq table
class Solution2 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& get_top = [](auto& heap, auto& cnt, auto& total) {
            while (cnt.count(heap.top())) {
                const int x = heap.top(); heap.pop();
                if (--cnt[x] == 0) {
                    cnt.erase(x);
                }
                --total;
            }
            return heap.top();
        };

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> cnt1, cnt2;
        int total1 = 0, total2 = 0;
        int64_t mn = INF, curr = 0;
        for (int i = 1; i < size(nums); ++i) {
            max_heap.emplace(nums[i]);
            curr += nums[i];
            if (size(max_heap) - total1 > k - 1) {
                const int x = get_top(max_heap, cnt1, total1); max_heap.pop();
                curr -= x;
                min_heap.emplace(x);
                
            }
            if ((size(max_heap) - total1) + (size(min_heap) - total2) > 1 + dist) {
                if (get_top(min_heap, cnt2, total2) <= nums[i - (1 + dist)]) {
                    lazy_delete(min_heap, cnt2, total2, nums[i - (1 + dist)]);
                } else {
                    lazy_delete(max_heap, cnt1, total1, nums[i - (1 + dist)]);
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

private:
    template<typename T>
    void lazy_delete(T& heap, auto& cnt, int& total, int x) {
        ++cnt[x];
        ++total;
        if (total <= size(heap) - total) {
            return;
        }
        T new_heap;
        while (!empty(heap)) {
            const auto x = heap.top(); heap.pop();
            if (cnt.count(x)) {
                if (--cnt[x] == 0) {
                    cnt.erase(x);
                }
                continue;
            }
            new_heap.emplace(x);
        }
        total = 0;
        heap = move(new_heap);
    }
};

// Time:  O(nlogd)
// Space: O(d)
// fast but verbose
// sliding window, bst
class Solution3 {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        multiset<int> bst1, bst2;
        int64_t mn = INF, curr = 0;
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// concise but slow
// sliding window, ordered set
class Solution4 {
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
