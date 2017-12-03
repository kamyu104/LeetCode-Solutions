// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> stk;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() &&
                   temperatures[stk.top()] < temperatures[i]) {
                const auto idx = stk.top(); stk.pop();
                result[idx] = i - idx;
            }
            stk.emplace(i);
        }
        return result; 
    }
};
