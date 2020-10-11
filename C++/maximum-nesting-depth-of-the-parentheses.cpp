// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int result = 0, curr = 0;
        for (const auto& c : s) {
            if (c == '(') {
                result = max(result, ++curr);
            } else if (c == ')') {
                --curr;
            }
        }
        return result;
    }
};
