// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> friends(n, vector<int>(n));
        for (int i = 0; i < size(preferences); ++i) {
            for (int j = 0; j < size(preferences[i]); ++j) {
                friends[i][preferences[i][j]] = j;
            }
        }
        vector<int> pairing(n);
        for (const auto &p : pairs) {
            pairing[p[0]] = p[1];
            pairing[p[1]] = p[0];
        }

        int result = 0;
        for (int i = 0; i < size(friends); ++i) {
            for (int j = 0; j < size(friends[i]); ++j) {
                if (j == i || j == pairing[i]) {
                    continue;
                }
                if (friends[i][j] < friends[i][pairing[i]] &&
                    friends[j][i] < friends[j][pairing[j]]) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
