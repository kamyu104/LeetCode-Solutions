// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        const auto& n = senate.length();
        for (int i = 0; i < n; ++i) {
            (senate[i] == 'R') ? radiant.emplace(i) : dire.emplace(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front(), d_idx = dire.front();
            radiant.pop(), dire.pop();
            (r_idx < d_idx) ? radiant.emplace(r_idx + n) : dire.emplace(d_idx + n);
        }
        return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
    }
};
