// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q({start});
        unordered_set<int> lookup = {start};
        while (!q.empty()) {
            const auto i = q.front(); q.pop();
            if (!arr[i]) {
                return true;
            }
            for (const auto& j : {i - arr[i], i + arr[i]}) {
                if (0 <= j && j < arr.size() && !lookup.count(j)) {
                    lookup.emplace(j);
                    q.emplace(j);
                }
            }
        }
        return false;
    }
};
