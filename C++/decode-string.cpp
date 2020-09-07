// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string decodeString(string s) {
        string curr;
        vector<int> nums;
        vector<string> strs;
        int n = 0;
        for (const auto& c: s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else if (isalpha(c)) {
                curr += c;
            } else if (c == '[') {
                nums.emplace_back(n);
                strs.emplace_back(curr);
                n = 0;
                curr.clear();
            } else if (c == ']') {
                for (; nums.back() > 0; --nums.back()) {
                    strs.back() += curr;
                }
                nums.pop_back();
                curr = move(strs.back()); strs.pop_back();
            }
        }
        return curr;
    }
};
