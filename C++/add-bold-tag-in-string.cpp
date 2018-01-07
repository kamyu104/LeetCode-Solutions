// Time:  O(s * d * l), l is the average string length
// Space: O(s)

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> lookup(s.length());
        for (const auto& d: dict) {
            auto pos = -1;
            while ((pos = s.find(d, pos + 1)) != string::npos) {
                fill(lookup.begin() + pos, lookup.begin() + pos + d.length(), true);
            }
        }
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (lookup[i] && (i == 0 || !lookup[i - 1])) {
                result += "<b>";
            }
            result.push_back(s[i]);
            if (lookup[i] && (i == (s.length() - 1) || !lookup[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }
};
