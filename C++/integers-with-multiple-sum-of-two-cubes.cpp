// Time:  O(n^(2/3) * logn)
// Space: O(n^(2/3))

// freq table
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> cnt;
        for (int i = 1; i * i * i <= n; ++i) {
            for (int j = i; j * j * j <= n - i * i * i; ++j) {
                ++cnt[i * i * i + j * j * j];
            }
        }
        vector<int> result;
        for (const auto& [k, v] : cnt) {
            if (v >= 2) {
                result.emplace_back(k);
            }
        }
        sort(begin(result), end(result));
        return result;
    }
};
