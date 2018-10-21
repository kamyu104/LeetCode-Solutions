// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int flip0 = 0, flip1 = 0;
        for (const auto& c : S) {
            flip0 += static_cast<int>(c == '1');
            flip1 = min(flip0, flip1 + static_cast<int>(c == '0'));
        }
        return flip1;
    }
};
