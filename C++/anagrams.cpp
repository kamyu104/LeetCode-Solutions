// Time:  O(n * glogg), g is the max size of groups.
// Space: O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strs) {
            string tmp{str};
            sort(tmp.begin(), tmp.end());
            groups[tmp].emplace_back(str);
        }

        vector<vector<string>> anagrams;
        for (const auto& kvp : groups) {
            vector<string> group;
            for (const auto& str : kvp.second) {
                group.emplace_back(str);
            }
            sort(group.begin(), group.end());
            anagrams.emplace_back(move(group));
        }

        return anagrams;
    }
};
