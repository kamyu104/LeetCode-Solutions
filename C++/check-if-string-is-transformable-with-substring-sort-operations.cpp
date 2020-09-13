// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> idxs(10);
        for (int i = size(s) - 1; i >= 0; --i) {
            idxs[s[i] - '0'].emplace_back(i);
        }
        for (const auto& c : t) {
            int d = c - '0';
            if (empty(idxs[d])) {
                return false;
            }
            for (int i = 0; i < d; ++i) {  // a char can be moved left to the current position if it meets no smaller one
                if (!empty(idxs[i]) && idxs[i].back() < idxs[d].back()) {
                    return false;
                }
            }
            idxs[d].pop_back();
        }
        return true;
    }
};
