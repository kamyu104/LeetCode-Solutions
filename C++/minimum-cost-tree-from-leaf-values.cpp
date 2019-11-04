// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        vector<int> stk = {numeric_limits<int>::max()};
        for (const auto& x : arr) {
            while (stk.back() <= x) {
                const auto mid = move(stk.back()); stk.pop_back();
                result += mid * min(stk.back(), x);
            }
            stk.emplace_back(x);
        }
        while (stk.size() > 2) {
            const auto right = move(stk.back()); stk.pop_back();
            result += right * stk.back();
        }
        return result;
    }
};
