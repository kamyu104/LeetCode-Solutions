// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        const auto& total = abs(target[0]) + abs(target[1]);
        return all_of(ghosts.cbegin(), ghosts.cend(),
                      [&target, &total](const vector<int>& ghost) {
                          return total < abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
                      });
    }
};
