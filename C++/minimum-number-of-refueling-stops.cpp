// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> max_heap;
        stations.push_back(vector<int>{target, numeric_limits<int>::min()});

        int result = 0, prev = 0;
        for (const auto& station : stations) {
            startFuel -= station[0] - prev;
            while (!max_heap.empty() && startFuel < 0) {
                startFuel += max_heap.top(); max_heap.pop();
                ++result;
            }
            if (startFuel < 0) {
                return -1;
            }
            max_heap.emplace(station[1]);
            prev = station[0];
        }
        return result;
    }
};
