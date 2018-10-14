// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minAddToMakeValid(string S) {
        int add = 0, bal = 0;
        for (const auto& c : S) {
            bal += c == '(' ? 1 : -1;
            if (bal == -1) {
                ++add;
                ++bal;
            }
        }
        return add + bal;
    }
};
