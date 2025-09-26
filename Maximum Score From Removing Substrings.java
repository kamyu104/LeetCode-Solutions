class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int res = 0;
        stack<char> st;

        // First pass: remove "ab" (or "ba" if x < y was true and we reversed)
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                res += x;
            } else {
                st.push(c);
            }
        }

        // Rebuild remaining string after first pass
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Second pass: remove "ba" (or "ab" if reversed earlier)
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                res += y;
            } else {
                st.push(c);
            }
        }

        return res;
    }
};
