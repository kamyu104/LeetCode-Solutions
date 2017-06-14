// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool isValid(string code) {
        auto i = 0;
        return validTag(code, &i) && i == code.size();
    }

private:
    bool validTag(const string& s, int *i) {
        auto j = *i;
        auto tag = parseTagName(s, &j);
        if (tag.empty()) {
            return false;
        }
        if (!validContent(s, &j)) {
            return false;
        }
        auto k = j + tag.size() + 2; 
        if (k >= s.size() || s.substr(j, k + 1 - j) != "</" + tag + ">") {
            return false;
        }
        *i = k + 1;
        return true;
    }

    string parseTagName(const string& s, int *i) {
        if (s[*i] != '<') {
            return "";
        }
        auto j = s.find('>', *i);
        if (j == string::npos || j - 1 - *i < 1 || 9 < j - 1 - *i) {
            return "";
        }
        auto tag = s.substr(*i + 1, j - 1 - *i);
        for (const auto& c : tag) {
            if (c < 'A' || 'Z' < c) {
                return "";
            }
        }
        *i = j + 1;
        return tag;
    }

    bool validContent(const string& s, int *i) {
        auto j = *i;
        while (j < s.size()) {
            if (!validText(s, &j) && !validCData(s, &j) && !validTag(s, &j)) {
                break;
            }
        }
        *i = j;
        return true;
    }

    bool validText(const string& s, int *i) {
        auto j = *i;
        *i = s.find("<", *i);
        return *i != j;
    }

    bool validCData(const string& s, int *i) {
        if (s.find("<![CDATA[", *i) != *i) {
            return false;
        }
        auto j = s.find("]]>", *i);
        if (j == string::npos) {
            return false;
        }
        *i = j + 3;
        return true;
    }
};
