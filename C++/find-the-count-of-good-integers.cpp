// Time:  O(10^(n/2))
// Space: O(n + nHr(10, n/2))

// combinatorics
class Solution {
private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

public:
    long long countGoodIntegers(int n, int k) {
        const auto& reverse = [](int x, int n) {
            if (n % 2) {
                x /= 10;
            }
            int result = 0;
            for (; x; x /= 10) {
                result = result * 10 + x % 10;
            }
            return result;
        };

        const auto& palindrome = [&](int64_t x, int n) {
            return x * pow(10, n / 2) + reverse(x, n);
        };

        const auto& count = [](auto x) {
            vector<int> cnt(10);
            for (; x; x /= 10) {
                ++cnt[x % 10];
            }
            return cnt;
        };

        vector<int> fact(n + 1, 1);
        for (int i = 0; i + 1 < size(fact); ++i) {
            fact[i + 1] = fact[i] * (i + 1);
        }
        const int l = (n + 1) / 2;
        int64_t result = 0;
        unordered_set<vector<int>, VectorHash<int>> lookup;
        const int upper_bound = pow(10, l);
        for (int d = pow(10, l - 1); d < upper_bound; ++d) {
            const int64_t x = palindrome(d, n);
            const auto& cnt = count(x);
            if (x % k || lookup.count(cnt)) {
                continue;
            }
            lookup.emplace(cnt);
            int64_t total = (n - cnt[0]) * fact[n - 1];
            for (const auto& c : cnt) {
                total /= fact[c];
            }
            result += total;
        }
        return result;
    }
};
