// Time:  O(n + tlogt)
// Space: O(n)

// freq table, sort, greedy
class Solution {
public:
    long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
        unordered_map<int, int> cnt;
        for (const int& x : workers) {
            ++cnt[x];
        }
        sort(begin(tasks), end(tasks), [](const auto& a, const auto& b) {
            return a[1] > b[1];
        });
        int64_t result = 0;
        int k = 1;
        for (const auto& t : tasks) {
            if (cnt[t[0]]) {
                --cnt[t[0]];
                result += t[1];
            } else if (k) {
                --k;
                result += t[1];
            }
        }
        return result;
    }
};
