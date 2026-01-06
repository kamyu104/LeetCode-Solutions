// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    string largestEven(string s) {
        while (!empty(s) && s.back() == '1') {
            s.pop_back();
        }
        return s;
    }
};
