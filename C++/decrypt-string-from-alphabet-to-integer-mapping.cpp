// Time:  O(n)
// Space: O(1)

// forward solution
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        int i = 0;
        while (i < s.length()) {
            if (i + 2 < s.length() && s[i + 2] == '#') {
                result.push_back(alpha(s.substr(i, 2)));
                i += 3;
            } else {
                result.push_back(alpha(s.substr(i, 1)));
                ++i;
            }
        }
        return result;
    }

private:
    char alpha(const string& s) {
        return 'a' + stoi(s) - 1;
    }
};

// Time:  O(n)
// Space: O(1)
// backward solution
class Solution2 {
public:
    string freqAlphabets(string s) {
        string result;
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                result.push_back(alpha(s.substr(i - 2, 2)));
                i -= 3;
            } else {
                result.push_back(alpha(s.substr(i, 1)));
                --i;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    char alpha(const string& s) {
        return 'a' + stoi(s) - 1;
    }
};

// Time:  O(n)
// Space: O(1)
// regex solution
class Solution3 {
public:
    string freqAlphabets(string s) {
        string result;
        int submatches[] = { 1, 2 };
        const auto e = regex("(\\d\\d#)|(\\d)");
        for (regex_token_iterator<string::const_iterator> it(s.cbegin(), s.cend(), e, submatches), end;
             it != end;) {
            const auto& a = (it++)->str();
            const auto& b = (it++)->str();
            result.push_back(alpha(!a.empty() ? a : b));
        }
        return result;
    }

private:
    char alpha(const string& s) {
        return 'a' + stoi(s) - 1;
    }
};
