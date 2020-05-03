// Time:  O(n + l)
// Space: O(1)

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left_shift = 0;
        for (const auto& x : shift) {
            if (!x[0]) {
                left_shift += x[1];
            } else {
                left_shift -= x[1];
            }
        }
        left_shift = ((left_shift) % int(s.length()) + int(s.length())) % int(s.length());
        reverse(begin(s), begin(s) + left_shift);
        reverse(begin(s) + left_shift, end(s));
        reverse(begin(s), end(s));
        return s;
    }
};
