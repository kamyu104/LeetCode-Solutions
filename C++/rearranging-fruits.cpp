// Time:  O(n) on average
// Space: O(n)

// freq table, greedy, quick select
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt;
        for (const auto& x : basket1) {
            ++cnt[x];
        }
        for (const auto& x : basket2) {
            --cnt[x];
        }
        const int mn = min_element(cbegin(cnt), cend(cnt))->first;
        vector<int> arr;
        for (const auto& [k, v] : cnt) {
            if (v % 2) {
                return -1;
            }
            for (int _ = 0; _ < abs(v) / 2; ++_) {
                arr.emplace_back(k);
            }   
        }
        nth_element(begin(arr), begin(arr) + size(arr) / 2, end(arr));
        int64_t result = 0;
        for (int i = 0; i < size(arr) / 2; ++i) {
            result += min(arr[i], mn * 2);
        }
        return result;
    }
};
