// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < arr.size(); ++i) {
            groups[arr[i]].emplace_back(i);
        }
        int result = 0;
        queue<pair<int, int>> q({{0, 0}});
        unordered_set<int> lookup = {0};
        while (!q.empty()) {
            const auto [pos, step] = q.front(); q.pop();
            if (pos == arr.size() - 1) {
                result = step;
                break;
            }
            unordered_set<int> neighbors(groups[arr[pos]].cbegin(),
                                         groups[arr[pos]].cend());
            groups[arr[pos]].clear();
            neighbors.emplace(pos - 1), neighbors.emplace(pos + 1);
            for (const auto& p : neighbors) {
                if (0 <= p && p < arr.size() && !lookup.count(p)) {
                    lookup.emplace(p);
                    q.emplace(p, step + 1);
                }
            }
        }
        return result;
    }
};
