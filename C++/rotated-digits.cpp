// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int rotatedDigits(int N) {
        enum State {INVALID, SAME, DIFF};
        unordered_set<int> same = {0, 1, 8};
        unordered_set<int> diff = {2, 5, 6, 9};
        vector<State> dp(N + 1);
        dp[0] = SAME;
        for (int i = 0; 10 * i <= N; ++i) {
            if (dp[i] != INVALID) {
                for (const auto& j : same) {
                    if (i * 10 + j <= N) {
                        dp[i * 10 + j] = max(SAME, dp[i]);
                    }
                }
                for (const auto& j : diff) {
                    if (i * 10 + j <= N) {
                        dp[i * 10 + j] = DIFF;
                    }
                }
            }
        }
        return count(dp.cbegin(), dp.cend(), DIFF);
    }
    
};

// Time:  O(nlogn) = O(n), because O(logn) = O(32) by this input
// Space: O(logn) = O(1)
class Solution2 {
public:
    int rotatedDigits(int N) {
        int result = 0;
        for (int i = 0; i <= N; ++i){
            string s(to_string(i));
            unordered_set<char> lookup(s.begin(),s.end());
            if (lookup.count('3') ||
                lookup.count('4') ||
                lookup.count('7')) {
                continue;
            }
            if (lookup.count('2') ||
                lookup.count('5') ||
                lookup.count('6') ||
                lookup.count('9')) {
                ++result;
            }
        }
        return result; 
    }
};
