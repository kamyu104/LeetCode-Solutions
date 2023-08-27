// Time:  O(n)
// Space: O(logn)

// codeforces, https://codeforces.com/problemset/problem/1303/D
// counting sort, greedy
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const auto& floor_log2_x = [](int x) {
            return 8 * sizeof(int) - __builtin_clz(x) - 1;
        };

        int64_t total = accumulate(begin(nums), end(nums), 0ll);
        if (total < target) {
            return -1;
        }
        vector<int> cnt(floor_log2_x(*max_element(cbegin(nums), cend(nums))) + 1);
        for (const auto& x : nums) {
            ++cnt[floor_log2_x(x)];
        }
        int result = 0;
        for (int i = size(cnt) - 1; i >= 0; --i) {
            const int x = 1 << i;
            for (int _ = 0; _ < cnt[i]; ++_) { 
                if (x <= target) {
                    target -= x;
                    total -= x;
                } else if (total - x >= target) {
                    total -= x;
                } else {
                    cnt[i - 1] += 2;
                    ++result;
                }
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// codeforces, https://codeforces.com/problemset/problem/1303/D
// sort, greedy
class Solution2 {
public:
    int minOperations(vector<int>& nums, int target) {
        int64_t total = accumulate(begin(nums), end(nums), 0ll);
        if (total < target) {
            return -1;
        }
        sort(begin(nums), end(nums));
        int result = 0;
        while (target) {
            const int x = nums.back(); nums.pop_back();
            if (x <= target) {
                target -= x;
                total -= x;
            } else if (total - x >= target) {
                total -= x;
            } else {
                nums.emplace_back(x / 2);
                nums.emplace_back(x / 2);
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// codeforces, https://codeforces.com/problemset/problem/1303/D
// heap, greedy
class Solution3 {
public:
    int minOperations(vector<int>& nums, int target) {
        int64_t total = accumulate(begin(nums), end(nums), 0ll);
        if (total < target) {
            return -1;
        }
        int result = 0;
        priority_queue<int> max_heap(cbegin(nums), cend(nums));
        while (target) {
            const int x = max_heap.top(); max_heap.pop();
            if (x <= target) {
                target -= x;
                total -= x;
            } else if (total - x >= target) {
                total -= x;
            } else {
                max_heap.emplace(x / 2);
                max_heap.emplace(x / 2);
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(nlogr)
// Space: O(logr)
// codeforces, https://codeforces.com/problemset/problem/1303/D
// bitmasks, greedy
class Solution4 {
public:
    int minOperations(vector<int>& nums, int target) {
        const auto& floor_log2_x = [](int x) {
            return 8 * sizeof(int) - __builtin_clz(x) - 1;
        };

        if (accumulate(begin(nums), end(nums), 0ll) < target) {
            return -1;
        }
        vector<int> cnt(floor_log2_x(*max_element(cbegin(nums), cend(nums))) + 1);
        for (const auto& x : nums) {
            ++cnt[floor_log2_x(x)];
        }
        int result = 0, i = 0;
        while (i < size(cnt)) {
            if (target & (1 << i)) {
                if (!cnt[i]) {
                    for (; i < size(cnt) && !cnt[i]; ++i) {
                        ++result;
                    }
                    --cnt[i];
                    continue;
                }
                --cnt[i];
            }
            if (i + 1 < size(cnt)) {
                cnt[i + 1] += cnt[i] / 2;
            }
            ++i;
        }
        return result;
    }
};
