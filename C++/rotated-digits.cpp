// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int rotatedDigits(int N) {
        enum State {INVALID, SAME, DIFF};
        const vector<int> same = {0, 1, 8};
        const vector<int> diff = {2, 5, 6, 9};
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
        const unordered_set<char> invalid = {'3', '4', '7'};
        const unordered_set<char> diff = {'2', '5', '6', '9'};
        int result = 0;
        for (int i = 0; i <= N; ++i){
            string s(to_string(i));
            unordered_set<char> lookup(s.begin(),s.end());
            if (intersect(invalid, lookup)) {
                continue;
            }
            if (intersect(diff, lookup)) {
                ++result;
            }
        }
        return result; 
    }

private:
    template <typename T>
    bool intersect(const unordered_set<T>& a, const unordered_set<T>& b) {
        if (a.size() > b.size()) {
            return intersect(b, a);
        }
        return any_of(a.cbegin(), a.cend(),
                      [&b](const T& e) {
                          return b.count(e);
                      });
    }
};
