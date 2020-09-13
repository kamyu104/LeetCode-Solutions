// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> idx(10);
        for (int i = size(s) - 1; i >= 0; --i) {
            idx[s[i] - '0'].emplace_back(i);
        }
        for (const auto& c : t) {
            int d = c - '0';
            if (idx[d].empty()) {
                return false;
            }
            for (int i = 0; i < d; ++i) {  // a char can be moved left to the current position if it meets no smaller one
                if (!idx[i].empty() && idx[i].back() < idx[d].back()) {
                    return false;
                }
            }
            idx[d].pop_back();
        }
        return true;
    }
};
