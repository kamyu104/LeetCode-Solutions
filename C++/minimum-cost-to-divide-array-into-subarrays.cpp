// Time:  O(nlogn)
// Space: O(n)

// prefix sum, dp, convex hull trick
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        vector<int64_t> prefix1(size(nums) + 1);
        vector<int64_t> prefix2(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix1[i + 1] = prefix1[i] + nums[i];
            prefix2[i + 1] = prefix2[i] + cost[i];
        }
        int64_t dp = 0;
        LineContainer lc;
        for (int i = size(nums) - 1; i >= 0; --i) {
            lc.add(prefix1[i + 1], -(dp + prefix1[i + 1] * prefix2[i + 1]));
            dp = (-lc.query(prefix2[i])) + (k * (prefix2.back() - prefix2[i]));
        }
        return dp;
    }

private:
    // Reference: https://usaco.guide/adv/line-container
    // Template: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
    using ll = long long;
    struct Line {
        mutable ll k, m, p;
        bool operator<(const Line& o) const { return k < o.k; }
        bool operator<(ll x) const { return p < x; }
    };

    struct LineContainer : multiset<Line, less<>> {
        // (for doubles, use inf = 1/.0, div(a,b) = a/b)
        static const ll inf = LLONG_MAX;
        ll div(ll a, ll b) { // floored division
            return a / b - ((a ^ b) < 0 && a % b); }
        bool isect(iterator x, iterator y) {
            if (y == end()) return x->p = inf, 0;
            if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
            else x->p = div(y->m - x->m, x->k - y->k);
            return x->p >= y->p;
        }
        void add(ll k, ll m) {
            auto z = insert({k, m, 0}), y = z++, x = y;
            while (isect(y, z)) z = erase(z);
            if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
            while ((y = x) != begin() && (--x)->p >= y->p)
                isect(x, erase(y));
        }
        ll query(ll x) {
            assert(!empty());
            auto l = *lower_bound(x);
            return l.k * x + l.m;
        }
    };
};

// Time:  O(n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        vector<int64_t> prefix1(size(nums) + 1);
        vector<int64_t> prefix2(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix1[i + 1] = prefix1[i] + nums[i];
            prefix2[i + 1] = prefix2[i] + cost[i];
        }
        vector<int64_t> dp(size(nums) + 1, numeric_limits<int64_t>::max());
        dp.back() = 0;
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int j = i; j < size(nums); ++j) {
                dp[i] = min(dp[i], prefix1[j + 1] * (prefix2[j + 1] - prefix2[i]) + dp[j + 1] + (k * (prefix2.back() - prefix2[i])));
            }
        }
        return dp[0];
    }
};
