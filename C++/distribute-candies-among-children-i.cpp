// Time:  O(1)
// Space: O(1)

// stars and bars, combinatorics, principle of inclusion and exclusion
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        const auto& nCr = [](int n, int r) {  // Time: O(n), Space: O(1)
            if (!(0 <= r && r <= n)) {
                return static_cast<int64_t>(0);
            }
            if (n - r < r) {
                r = n - r;
            }
            int64_t result = 1;
            for (int k = 1; k <= r; ++k) {
                result *= n - k + 1;
                result /= k;
            }
            return result;
        };
        
        const auto& nHr = [&](int n, int r) {
            return nCr(n + (r - 1), r - 1);
        };
    
        static const int R = 3;
    
        int64_t result = 0;
        for (int r = 0; r <= R; ++r) {
            result += (r % 2 ? -1 : 1) * nCr(R, r) * nHr(n - r * (limit + 1), R);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// optimized brute force
class Solution2 {
public:
    long long distributeCandies(int n, int limit) {
        int64_t result = 0;
        for (int i = max(n - 2 * limit, 0); i <= min(limit, n); ++i) {
            result += min(limit, n - i) - max((n - i) - limit, 0) + 1;
        }
        return result;
    }
};


// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution3 {
public:
    long long distributeCandies(int n, int limit) {
        int64_t result = 0;
        for (int i = 0; i <= min(limit, n); ++i) {
            for (int j = 0; j <= min(limit, n - i); ++j) {
                if (n - i - j <= limit) {
                    ++result;
                }
            }
        }
        return result;
    }
};
