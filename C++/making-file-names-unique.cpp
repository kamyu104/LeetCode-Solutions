// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> count;
        vector<string> result;
        unordered_set<string> lookup;
        for (const auto& name : names) {
            auto& c = count[name];
            string name_with_suffix;
            do {
                name_with_suffix = c ? name + "(" + to_string(c) + ")" : name;
                ++c;
            } while (lookup.count(name_with_suffix));
            result.emplace_back(name_with_suffix);
            lookup.emplace(move(name_with_suffix));
        }
        return result;
    }
};
