// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    string removeStars(string s) {
        string result;
        for (const auto& c : s) {
            if (c == '*') {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
