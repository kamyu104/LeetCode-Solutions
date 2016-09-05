// Time:  O(n)
// Space: O(h), h is the depth of the recursion

class Solution {
public:
    string decodeString(string s) {
        string curr;
        stack<int> nums;
        stack<string> strs;
        int n = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                n = n * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                nums.emplace(n);
                n = 0;
                strs.emplace(curr);
                curr.clear();
            } else if (s[i] == ']') {
                for (; nums.top() > 0; --nums.top()) {
                    strs.top() += curr;
                }
                nums.pop();
                curr = strs.top();
                strs.pop();
            } else {
                curr += s[i];
            }
        }
        return strs.empty() ? curr : strs.top();
    }
};
