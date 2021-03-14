// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            jobs.emplace_back(endTime[i], startTime[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        vector<pair<int, int>> dp = {{0, 0}};
        for (const auto& [e, s, p] : jobs) {
            const auto& it = prev(upper_bound(dp.cbegin(),
                                              dp.cend(),
                                              make_pair(s + 1, 0)));
            if (it->second + p > dp.back().second) {
                dp.emplace_back(e, it->second + p);
            }
        }
        return dp.back().second;
    }
};


// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> min_heap;
        for (int i = 0; i < startTime.size(); ++i) {
            min_heap.emplace_back(startTime[i], endTime[i], profit[i]);
        }
        make_heap(min_heap.begin(), min_heap.end(), greater<>());
        int result = 0;
        while (!min_heap.empty()) {
            const auto [s, e, p] = min_heap.front();
            pop_heap(begin(min_heap), end(min_heap), greater<>()); min_heap.pop_back();
            if (s < e) {
                min_heap.emplace_back(e, s, result + p); push_heap(begin(min_heap), end(min_heap), greater<>());
            } else {
                result = max(result, p);
            }
        }
        return result;
    }
};
