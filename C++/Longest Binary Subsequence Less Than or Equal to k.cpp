class Solution {
public:
    int longestSubsequence(string s, int k) {
     int n = s.length();
    int count = 0;
    long long val = 0;
    int power = 0;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            count++; // 0 KABHI BHI VALUE KOO BADHATE NAHI HAI 
        } else {
            if (power < 32) {
                val += (1LL << power);
                if (val <= k) {
                    count++;
                } else {
                    val -= (1LL << power); // undo
                }
            }
        }
        power++;
    }

    return count;
    }
};
