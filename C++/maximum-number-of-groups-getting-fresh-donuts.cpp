// Time:  O(b * (n/b+1)^b)
// Space: O((n/b+1)^b)

// greedy + dp solution
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize);
        for (const auto& i : groups) {
            ++count[i % size(count)];
        }
        int max_mask = accumulate(cbegin(count), cend(count), 1,
                                  [](int total, int c) {
                                      return total * (c + 1);
                                  });
        vector<int> dp(max_mask);
        return dfs(count, dp, max_mask - 1, 0);
    }

private:
    int dfs(vector<int>& count, vector<int>& dp, int mask, int remain) {
        if (dp[mask]) {
            return dp[mask];
        }
        int curr = mask, basis = 1, i = 0;
        for (; i < remain; basis *= (count[i] + 1), curr /= (count[i] + 1), ++i);
        // mask: a0 + a1 * (c0 + 1)  + a2 * (c0 + 1) * (c1 + 1) + ... + a(b-1) * (c0 + 1) * (c1 + 1) * ... * (c(b-2) + 1)
        int a_remain = curr % (count[remain] + 1);
        int result = 0;
        if (a_remain) {  // greedily use remain
            result = max(result, (remain == 0) + dfs(count, dp, mask - basis, ((remain - i) + size(count)) % size(count)));
        } else {
            for (int curr = mask, basis = 1, i = 0; i < size(count); basis *= (count[i] + 1), curr /= (count[i] + 1), ++i) {
                if (curr % (count[i] + 1) == 0) {
                    continue;
                }
                result = max(result, (remain == 0) + dfs(count, dp, mask - basis, ((remain - i) + size(count)) % size(count)));
            }
        }
        return dp[mask] = result;
    }
};

// Time:  O(b * (n/b+1)^b)
// Space: O((n/b+1)^b)
// dp solution
class Solution2 {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize);
        for (const auto& i : groups) {
            ++count[i % size(count)];
        }
        int max_mask = accumulate(cbegin(count), cend(count), 1,
                                  [](int total, int c) {
                                      return total * (c + 1);
                                  });
        vector<int> dp(max_mask);
        int result = 0;
        for (int mask = 0; mask < size(dp); ++mask) {
            dp[mask] = 0;
            int remain = 0;
            for (int curr = mask, basis = 1, i = 0; i < size(count);
                 basis *= (count[i] + 1), curr /= (count[i] + 1), ++i) {  // decode mask
                // mask: a0 + a1 * (c0 + 1)  + a2 * (c0 + 1) * (c1 + 1) + ... + a(b-1) * (c0 + 1) * (c1 + 1) * ... * (c(b-2) + 1)
                int ai = curr % (count[i] + 1);
                if (ai > 0) {
                    dp[mask] = max(dp[mask], dp[mask - basis]);
                }
                remain = (remain + ai * i) % size(count);
            }
            if (mask != size(dp) - 1 && remain == 0) {
                ++dp[mask];
            }
        }
        return dp.back();
    }
};
