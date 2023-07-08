// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        vector<int> stk = {nodes[0][0]};
        for (int i = 1; i < size(nodes); ++i) {
            while (!empty(stk) && stk.back() != nodes[i][1]) {
                stk.pop_back();
            }
            if (empty(stk)) {
                return false;
            }
            stk.emplace_back(nodes[i][0]);
        }
        return true;
    }
};
