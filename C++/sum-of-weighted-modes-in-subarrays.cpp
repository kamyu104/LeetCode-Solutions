// Time:  O(nlogk)
// Space: O(k)

// bst, two pointers, sliding window
class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        set<pair<int, int>> bst;
        const auto& add = [&](int x, int diff) {
            if (cnt[x]) {
                bst.erase(pair(-cnt[x], x));
            }
            cnt[x] += diff;
            if (cnt[x]) {
                bst.emplace(-cnt[x], x);
            } else {
                cnt.erase(x);
            }
        };

        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            add(nums[i], +1);
            if (i >= k - 1) {
                result += static_cast<int64_t>(-cbegin(bst)->first) * cbegin(bst)->second;
                add(nums[i - k + 1], -1);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bst, two pointers, sliding window
class Solution2 {
public:
    long long modeWeight(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>> max_heap;
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            ++cnt[nums[i]];
            max_heap.emplace(cnt[nums[i]], -nums[i]);
            if (i >= k - 1) {
                while (max_heap.top().first != cnt[-max_heap.top().second]) {
                    max_heap.pop();
                }
                result += static_cast<int64_t>(max_heap.top().first) * -max_heap.top().second;
                --cnt[nums[i - k + 1]];
            }
        }
        return result;
    }
};
