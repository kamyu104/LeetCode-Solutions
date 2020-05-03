// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> A, B;
        for (const auto& path : paths) {
            A.emplace(path[0]);
            B.emplace(path[1]);
        }
        for (const auto& dst : B) {
            if (!A.count(dst)) {
                return dst;
            }
        }
        return "";
    }
};
