// Time:  O(s * d * l), l is the average string length
// Space: O(s)

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> bold(s.length());
        for (const auto& d: dict) {
            auto pos = -1;
            while ((pos = s.find(d, pos + 1)) != string::npos) {
                fill(bold.begin() + pos, bold.begin() + pos + d.length(), true);
            }
        }
        string result;
        bool prev = false;
        for (int i = 0; i < s.length(); ++i) {
            if (prev != bold[i]) {
                result += prev ? "</b>" : "<b>";
                prev = bold[i];
            }
            result.push_back(s[i]);
        }
        if (prev) {
            result += "</b>";
        }
        return result;
    }
};