// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        const string PREV = "prev";

        vector<int> result, stk;
        int i = -1;
        for (const auto& x : words) {
            if (x == PREV) {
                result.emplace_back(i >= 0 ? stk[i--] : -1);
                continue;
            }
            stk.emplace_back(stoi(x));
            i = size(stk) - 1;
        }
        return result;
    }
};
