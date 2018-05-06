// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string maskPII(string S) {
        auto at = S.find("@");
        if (at != string::npos) {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
            return S.substr(0, 1) + "*****" + S.substr(at - 1);
        }
        string digits;
        for (const auto& c : S) {
            if (::isdigit(c)) {
                digits.push_back(c);
            }
        }
        string local{"***-***-"};
        local += digits.substr(digits.length() - 4);
        if (digits.length() == 10) {
            return local;
        }
        return "+" + string(digits.length() - 10, '*') + "-" + local;
    }
};
