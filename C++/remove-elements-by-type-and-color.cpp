// Time:  O(n)
// Space: O(n)

// stack, greedy
class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        vector<pair<int, int>> stk;
        for (int i = 0; i < size(types); ++i) {
            if (!(!empty(stk) && types[stk.back().first] == types[i] && colors[stk.back().first] == colors[i])) {
                stk.emplace_back(i, 0);
            }
            ++stk.back().second;
            if (stk.back().second == groupSize[types[i]]) {
                stk.pop_back();
            }
        }
        return empty(stk);
    }
};
