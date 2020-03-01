// Time:  O(m * (n + mlogm)), n is the number of votes
//                          , m is the length of vote
// Space: O(m^2)

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>> count;
        for (const auto& v : votes[0]) {
            count[v] = vector<int>(votes[0].size());
            count[v].emplace_back(static_cast<int>(v));
        }
        for (const auto& vote : votes) {
            for (int i = 0; i < vote.length(); ++i) {
                --count[vote[i]][i];
            }
        }
        sort(begin(votes[0]), end(votes[0]),
             [&count](const auto& a, const auto& b) {
                 return count[a] < count[b];
             });
        return votes[0];
    }
};
