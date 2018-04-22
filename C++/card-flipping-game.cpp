// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                same.emplace(fronts[i]);
            }
        }
        int result = numeric_limits<int>::max();
        for (const auto& n : fronts) {
            if (!same.count(n)) {
                result = min(result, n);
            }
        }
        for (const auto& n : backs) {
            if (!same.count(n)) {
                result = min(result, n);
            }
        }
        return result != numeric_limits<int>::max() ? result : 0;
    }
};
