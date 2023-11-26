// Time:  O(n + sqrt(k))
// Space: O(n)

// number theory, prefix sum, freq table
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
    
        vector<int> prefix(size(s) + 1);
        for (int i = 0; i < size(s); ++i) {
            prefix[i + 1] = prefix[i] + (VOWELS.count(s[i]) ? +1 : -1);
        }
        int new_k = 1;
        int x = k;
        for (int i = 2; i * i <= k; ++i) {
            int cnt = 0;
            for (; x % i == 0; x /= i) {
                ++cnt;
            }
            if (cnt) {
                new_k *= pow(i, (cnt + 1) / 2 + static_cast<int>(i == 2));
            }
        }
        if (x != 1) {
            new_k *= pow(x, (1 + 1) / 2 + static_cast<int>(x == 2));
        }
        unordered_map<int, unordered_map<int, int>> cnt;
        int result = 0;
        for (int i = 0; i < size(prefix); ++i) {
            result += cnt[prefix[i]][i % new_k]++;
        }
        return result;
    }
};

