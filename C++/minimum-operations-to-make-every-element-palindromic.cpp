// Time:  O(nlogr)
// Space: O(1)

// greedy
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        const auto& palindrome = [](int64_t i, int l) {
            const int64_t base = pow(10, (l + 1) / 2 - 1);
            int64_t rev = 0;
            for (int64_t x = i; x; x /= 10) {
                rev = rev * 10 + x % 10;
            }
            return l % 2 == 0 ? i * (base * 10) + rev : i * base + rev % base;
        };

        const auto& split = [](int64_t x) {
            int l = 0;
            for (int64_t t = x; t; t /= 10, ++l);
            const auto& k = (l + 1) / 2;
            const auto& h = x / pow(10, l - k);
            const auto& base = pow(10, k - 1);
            return tuple(l, h, base, h / base);
        };

        const auto& right = [&](int64_t x, int l, int64_t h, int64_t base, int64_t d) {
            const int64_t result = x % 2 ? pow(10, l) + 1 : 2 * pow(10, l) + 2;  // 10..01 / 20..02
            if (d % 2 != x % 2) {
                return d + 1 <= 9 ? palindrome((d + 1) * base, l) : result;      // (d+1)0..0(d+1)
            }
            const int64_t p = palindrome(h, l);
            if (p >= x) {
                return p;
            }
            if ((h + 1) / base == d) {
                return palindrome(h + 1, l);
            }
            return d + 2 <= 9 ? palindrome((d + 2) * base, l) : result;          // (d+2)0..0(d+2)
        };

        const auto& left = [&](int64_t x, int l, int64_t h, int64_t base, int64_t d) {
            int64_t result;
            if (l == 1) {
                result = -1;
            } else if (x % 2) {
                result = pow(10, l - 1) - 1;                                     // 99..99
            } else {
                result = palindrome(9 * pow(10, l / 2 - 1) - 1, l - 1);          // 89..98
            }
            if (d % 2 != x % 2) {
                return d - 1 >= 1 ? palindrome(d * base - 1, l) : result;        // (d-1)9..9(d-1)
            }
            const int64_t p = palindrome(h, l);
            if (p <= x) {
                return p;
            }
            if (h % base) {
                return palindrome(h - 1, l);
            }
            return d - 2 >= 1 ? palindrome((d - 1) * base - 1, l) : result;      // (d-2)9..9(d-2)
        };

        int64_t result = 0;
        for (const auto& x : nums) {
            const auto& [l, h, base, d] = split(x);
            int64_t mn = right(x, l, h, base, d) - x;
            const auto& t = left(x, l, h, base, d);
            if (t != -1) {
                mn = min(mn, x - t);
            }
            result += mn / 2;
        }
        return result;
    }
};

// Time:  precompute:  O(sqrt(r)), r = max(nums)
//        runtime:     O(nlogr)
// Space: O(sqrt(r))
// binary search
const int MAX_L = 10;
const auto& precompute = [](){
    vector<vector<int64_t>> result(2);
    int64_t base = 1;
    for (int l = 1; l <= MAX_L; ++l) {
        for (int64_t i = base; i < base * 10; ++i) {
            int64_t rev = 0;
            for (int64_t x = i; x; x /= 10) {
                rev = rev * 10 + x % 10;
            }
            result[rev % 2].emplace_back(l % 2 == 0 ? i * (base * 10) + rev : i * base + rev % base);
        }
        if (l % 2 == 0) {
            base *= 10;
        }
    }
    return result;
};

const auto& P = precompute();
class Solution2 {
public:
    long long minOperations(vector<int>& nums) {
        static const auto& INF = numeric_limits<int64_t>::max();

        int64_t result = 0;
        for (const auto& x : nums) {
            auto cit = ranges::lower_bound(P[x % 2], x);
            int64_t mn = INF;
            if (cit != cend(P[x % 2])) {
                mn = min(mn, *cit - x);
            }
            if (cit != cbegin(P[x % 2])) {
                mn = min(mn, x - *prev(cit));
            }
            result += mn / 2;
        }
        return result;
    }
};
