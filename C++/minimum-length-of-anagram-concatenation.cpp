// Time:  O(sqrt(n) * n + (26 * sum(n/i for i in range(1, n+1) if n%i == 0))) < O(sqrt(n) * n + 26 * sum(n/i for i in range(1, n+1)) = O(sqrt(n) * n + 26 * nlogn)
// Space: O(26)

// number theory, freq table
class Solution {
public:
    int minAnagramLength(string s) {
        const auto& check = [&](int l) {
            const auto& count = [&](int i) {
                vector<int> cnt(26);
                for (int j = i; j < i + l; ++j) {
                    ++cnt[s[j] - 'a'];
                }
                return cnt;
            };

            const auto& cnt = count(0);
            for (int i = l; i < size(s); i += l) {
                if (count(i) != cnt) {
                    return false;
                }
            }
            return true;
        };

        int result = size(s);
        for (int i = 1; i * i <= size(s); ++i) {
            if (size(s) % i) {
                continue;
            }
            if (check(i)) {
                result = min(result, i);
            }
            const int j = size(s) / i;
            if (j == i) {
                continue;
            }
            if (check(j)) {
                result = min(result, j);
            }
        }
        return result;
    }
};
