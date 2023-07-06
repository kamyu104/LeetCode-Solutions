// Time:  O(nlogn + mlogm)
// Space: O(n + m)

// sort, line sweep
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<tuple<int, int, int>> events;
        for (const auto& log : logs) {
            events.emplace_back(log[1], +1, log[0] - 1);
            events.emplace_back(log[1] + x + 1, -1, log[0] - 1);
        }
        events.emplace_back(numeric_limits<int>::max(), 0, 0);
        sort(begin(events), end(events));

        vector<pair<int, int>> events2;
        for (int i = 0; i < size(queries); ++i) {
            events2.emplace_back(queries[i], i);
        }
        sort(rbegin(events2), rend(events2));

        vector<int> result(size(queries));
        vector<int> cnt(n);
        int curr = 0;
        for (const auto& [t, c, i] : events) {
            while (!empty(events2) && events2.back().first < t) {                
                result[events2.back().second] += n - curr;
                events2.pop_back();
            }
            if (cnt[i] == 0) {
                ++curr;
            }
            cnt[i] += c;
            if (cnt[i] == 0) {
                --curr;
            }
        }
        return result;
    }
};
