// Time:  O(n)
// Space: O(h), h is the depth of the recursion

class Solution {
public:
    string decodeString(string s) {
        string curr;
        stack<int> nums;
        stack<string> strs;
        int n = 0;
        for (const auto& c: s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else if (c == '[') {
                nums.emplace(n);
                n = 0;
                strs.emplace(curr);
                curr.clear();
            } else if (c == ']') {
                for (; nums.top() > 0; --nums.top()) {
                    strs.top() += curr;
                }
                nums.pop();
                curr = strs.top();
                strs.pop();
            } else {
                curr += c;
            }
        }
        return strs.empty() ? curr : strs.top();
    }
};
