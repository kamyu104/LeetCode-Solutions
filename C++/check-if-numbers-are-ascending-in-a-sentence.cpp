// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1, curr = -1;
        for (const auto& c : s) {
            if (isdigit(c)) {
                curr = max(curr, 0) * 10 + (c - '0'); 
                continue;
            }
            if (prev != -1 && curr != -1 && prev >= curr) {
                return false;
            }
            if (curr != -1) {
                prev = curr;
            }
            curr = -1;
        }
        return (curr == -1 || prev < curr);
    }
};
