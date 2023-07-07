// Time:  O(nlogr)
// Space: O(1)

// number theory, freq table
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int result = 0;
        vector<int> cnt(10);
        for (auto x : nums) {
            for (int i = 1; i <= 9; ++i) {
                if (gcd(i, x % 10) == 1) {
                    result += cnt[i];
                }
            }
            while (x >= 10) {
                x /= 10;
            }
            ++cnt[x];
        }
        return result;
    }
};
