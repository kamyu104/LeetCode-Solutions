// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> groups;
        for (const auto& str : strings) {  // Grouping.
            groups[hashStr(str)].insert(str);
        }
        
        vector<vector<string>> result;
        for (const auto& kvp : groups) {
            vector<string> group;
            for (auto& str : kvp.second) {  // Sorted in a group.
                group.emplace_back(move(str));
            }
            result.emplace_back(move(group));
        }
        
        return result;
    }
    
    string hashStr(string str) {
        const char base = str[0];
        for (auto& c : str) {
            c = 'a' + ((c - base) >= 0 ? c - base : c - base + 26);
        }
        return str;
    }
};
