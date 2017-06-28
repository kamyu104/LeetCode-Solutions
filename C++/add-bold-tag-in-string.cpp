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
        for (int i = 0; i < s.length(); ++i) {
            if ((i == 0 || !bold[i - 1]) && bold[i]) {
                result += "<b>";
            } else if (i != 0 && bold[i - 1] && !bold[i]) {
                result += "</b>";
            }
            result.push_back(s[i]);
        }
        if (bold.back()) {
            result += "</b>";
        }
        return result;
    }
};

