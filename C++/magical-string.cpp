// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int magicalString(int n) {
        string S = "122";
        for (int i = 2; S.length() < n; ++i) { 
            S += string(S[i] - '0', S.back() ^ 3);
        }
        return count(S.begin(), S.begin() + n, '1');
    }
};
