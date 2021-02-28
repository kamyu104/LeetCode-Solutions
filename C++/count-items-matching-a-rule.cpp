// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        static const unordered_map<string, int> rule = {{"type", 0}, {"color", 1}, {"name", 2}};
        int result = 0;
        for (const auto& item : items) {
            if (item[rule.at(ruleKey)] == ruleValue) {
                ++result;
            }
        }
        return result;
    }
};
