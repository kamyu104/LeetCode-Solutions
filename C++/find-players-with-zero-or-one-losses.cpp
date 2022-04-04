// Time:  O(nlogn)
// Space: O(n)

// hash, sort
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lose;
        unordered_set<int> players_set;
        for (const auto& x : matches) {
            ++lose[x[1]];
            players_set.emplace(x[0]);
            players_set.emplace(x[1]);
        }
        vector<int> players(cbegin(players_set), cend(players_set));
        sort(begin(players), end(players));
        vector<vector<int>> result(2);
        for (const auto& x: players) {
            for (int i = 0; i < 2; ++i) {
                if (lose[x] == i) {
                    result[i].emplace_back(x);
                }
            }
        }
        return result;
    }
};
