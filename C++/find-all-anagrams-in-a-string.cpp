// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.empty() || s.empty()) {
            return result;
        }

        vector<int> cnts(26);
        for (const auto& c : p) {
            ++cnts[c - 'a'];
        }
        
        for (int left = 0, right = 0; right < s.length(); ++right) {
            --cnts[s[right] - 'a'];
            while (left <= right && cnts[s[right] - 'a'] < 0) {
                ++cnts[s[left++] - 'a'];
            }
            if (right - left + 1 == p.length()) {
                result.emplace_back(left);
            }
        }
        return result;
    }
};
