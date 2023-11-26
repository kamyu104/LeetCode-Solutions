// Time:  O(n)
// Space: O(n)

// dp, mono deque
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(prices), INF);
        dp[0] = prices[0];
        deque<int> dq;
        for (int i = 1, j = 1; i < size(prices); ++i) {
            while (!empty(dq) && dp[dq.back() - 1] + prices[dq.back()] >= dp[i - 1] + prices[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            if (i == 1) {
                dp[1] = prices[0];
                continue;
            }
            for (; j + (j + 1) < i; ++j) {
                assert(!empty(dq));
                if (dq.front() <= j) {
                    dq.pop_front();
                }
            }
            dp[i] = dp[dq.front() - 1] + prices[dq.front()];
        }
        return dp.back();
    }
};

// Time:  O(nlogn)
// Space: O(n)
// dp, bst
class Solution2 {
public:
    int minimumCoins(vector<int>& prices) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(prices), INF);
        dp[0] = prices[0];
        set<pair<int, int>> bst;
        for (int i = 1, j = 1; i < size(prices); ++i) {
            bst.emplace(dp[i - 1] + prices[i], i);
            if (i == 1) {
                dp[1] = prices[0];
                continue;
            }
            for (; j + (j + 1) < i; ++j) {
                bst.erase(pair(dp[j - 1] + prices[j], j));
            }
            dp[i] = dp[cbegin(bst)->second - 1] + prices[cbegin(bst)->second];
        }
        return dp.back();
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp
class Solution3 {
public:
    int minimumCoins(vector<int>& prices) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(prices), INF);
        dp[0] = prices[0];
        for (int i = 1; i < size(prices); ++i) {
            if (i == 1) {
                dp[1] = prices[0];
                continue;
            }
            for (int j = max(i / 2, 1); j <= i; ++j) {
                dp[i] = min(dp[i], dp[j - 1] + prices[j]);
            }
        }
        return dp.back();
    }
};
