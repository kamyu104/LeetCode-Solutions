// Time Complexity: O(klogk * n) ~= O(n), k is length of string, n is number of strings
// Space Complexity: O(k * n) ~= O(n)

class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            vector<string> ans;
            unordered_map<string, vector<string> > group;
            for(auto s : strs) {
                string k = s;
                sort(k.begin(), k.end());
                group[k].push_back(s);
            }

            for(auto it = group.cbegin(); it != group.cend(); ++it) {
                if(it->second.size() > 1)
                    ans.insert(ans.end(), it->second.begin(), it->second.end());
            }

            return ans;
        }
};`
