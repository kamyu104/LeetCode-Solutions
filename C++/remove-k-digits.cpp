// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        // If a digit is greater than next one, delete it.
        string s;
        for (const auto c : num) {
            while (k > 0 && !s.empty() && s.back() > c) {
                s.pop_back();
                --k;
            }
            s.push_back(c);
        }

        // If all digits are increasingly sorted, delete last.
        s.resize(s.length() - k);

        // Strip all leading '0'
        return s.empty() || s == "0" ? "0" : s.substr(s.find_first_not_of('0'));
    }
};
