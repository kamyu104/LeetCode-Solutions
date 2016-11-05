// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const auto& c : s) {
            ++freq[c];
        }
            
        vector<string> counts(s.size() + 1);
        for (const auto& kvp : freq) {
            counts[kvp.second].push_back(kvp.first);
        }
            
        string result;
        for (int count = counts.size() - 1; count >= 0; --count) {
            for (const auto& c : counts[count]) {
                result += string(count, c);
            }
        }
        
        return result;
    }
};
