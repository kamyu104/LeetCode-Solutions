// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> result;
        if (rounds.front() <= rounds.back()) {
            for (int i = rounds.front(); i <= rounds.back(); ++i) {
                result.emplace_back(i);
            }
        } else {
            for (int i = 1; i <= rounds.back(); ++i) {
                result.emplace_back(i);
            }
            for (int i = rounds.front(); i <= n; ++i) {
                result.emplace_back(i);
            }
        }
        return result;  
    }
};
