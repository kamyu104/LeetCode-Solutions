// Time:  O(m + n)
// Space: O(m + n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> lookup;
        for (const auto& num : nums) {
            while (!stk.empty() && num > stk.top()) {
                lookup[stk.top()] = num;
                stk.pop();
            }
            stk.emplace(num);
        }
        while (!stk.empty()) {
            lookup[stk.top()] = -1;
            stk.pop();
        }

        vector<int> result;
        for (const auto& num : findNums) {
            result.emplace_back(lookup[num]);
        }
        return result;
    }
};
