// Time:  O(k + nlogk)
// Space: O(k)

// heap, simulation
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        vector<pair<int, int>> workers;
        for (int i = 0; i < k; ++i) {
            workers.emplace_back(0, i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> left_ware(cbegin(workers), cend(workers)), right_ware;
        priority_queue<pair<int, int>> left_bridge, right_bridge;
        int result = 0;
        while (n) {
            while (!empty(left_ware) && left_ware.top().first <= result) {
                const auto [_, i] = left_ware.top(); left_ware.pop();
                left_bridge.emplace(time[i][0] + time[i][2], i);
            }
            while (!empty(right_ware) && right_ware.top().first <= result) {
                const auto [_, i] = right_ware.top(); right_ware.pop();
                right_bridge.emplace(time[i][0] + time[i][2], i);
            }
            if (!empty(right_bridge)) {
                const auto [_, i] = right_bridge.top(); right_bridge.pop();
                result += time[i][2];
                left_ware.emplace(result + time[i][3], i);
                --n;
            } else if (!empty(left_bridge) && n > size(right_ware)) {
                const auto [_, i] = left_bridge.top(); left_bridge.pop();
                result += time[i][0];
                right_ware.emplace(result + time[i][1], i);
            } else {
                result = min(!empty(left_ware) && n > size(right_ware) ? left_ware.top().first : numeric_limits<int>::max(),
                             !empty(right_ware) ? right_ware.top().first : numeric_limits<int>::max());
            }
        }
        return result;
    }
};
