// Time:  O(n * l^2)
// Space: O(n * l)

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) {
                 return less<int>()(a.length(), b.length());
             });
        unordered_map<string, int> dp;
        for (const auto& w : words) {
            for (int i = 0; i < w.length(); ++i) {
                auto tmp = w.substr(0, i);
                tmp += w.substr(i + 1);
                dp[w] = max(dp[w], dp[tmp] + 1);
            }
        }
        using pair_type = decltype(dp)::value_type;
        return max_element(dp.cbegin(), dp.cend(),
                           [] (const pair_type& a,
                               const pair_type& b) {
                               return a.second < b.second;
                           })->second;
    }
};
