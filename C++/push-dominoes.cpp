// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> force(dominoes.length());

        int f = 0;
        for (int i = 0; i < dominoes.length(); ++i) {
            if (dominoes[i] == 'R') {
                f = dominoes.length();
            } else if (dominoes[i] == 'L') {
                f = 0;
            } else {
                f = max(f - 1, 0);
            }
            force[i] += f;
        }

        f = 0;
        for (int i = dominoes.length() - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                f = dominoes.length();
            } else if (dominoes[i] == 'R') {
                f = 0;
            } else {
                f = max(f - 1, 0);
            }
            force[i] -= f;
        }
        string result;
        for (const auto& f : force) {
            result.push_back((f == 0) ? '.' : ((f > 0) ? 'R' : 'L'));
        }
        return result;
    }
};
