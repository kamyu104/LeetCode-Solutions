// Time:  O((b/2) * (n/(b/2)+1)^(b/2))
// Space: O((n/(b/2)+1)^(b/2))

// greedy + memoization solution
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize);
        for (const auto& i : groups) {
            ++count[i % size(count)];
        }
        int result = count[0];
        count[0] = 0;
        for (int i = 1; i <= size(count) / 2; ++i) {
            int pair_count = 2 * i != size(count) ? min(count[i], count[size(count) - i]) : count[i] / 2;
            result += pair_count;
            count[i] -= pair_count;
            count[size(count) - i] -= pair_count;
        }
        int max_mask = accumulate(cbegin(count), cend(count), 1,
                                  [](int total, int c) {
                                      return total * (c + 1);
                                  });
        vector<int> lookup(max_mask);
        return result + memoization(count, max_mask - 1, 0, &lookup);
    }

private:
    int memoization(const vector<int>& count, int mask, int remain, vector<int> *lookup) {
        if (!(*lookup)[mask]) {
            int curr = mask, basis = 1, i = 0;
            for (; i < remain; basis *= (count[i] + 1), curr /= (count[i] + 1), ++i);
            // mask: a0 + a1 * (c0 + 1)  + a2 * (c0 + 1) * (c1 + 1) + ... + a(b-1) * (c0 + 1) * (c1 + 1) * ... * (c(b-2) + 1)
            int a_remain = curr % (count[remain] + 1);
            int result = 0;
            if (a_remain) {  // greedily use remain
                result = max(result, (remain == 0) + memoization(count, mask - basis, 0, lookup));
            } else {
                for (int curr = mask, basis = 1, i = 0; i < size(count); basis *= (count[i] + 1), curr /= (count[i] + 1), ++i) {
                    if (curr % (count[i] + 1) == 0) {
                        continue;
                    }
                    result = max(result, (remain == 0) + memoization(count, mask - basis, ((remain - i) + size(count)) % size(count), lookup));
                }
            }
            (*lookup)[mask] = result;
        }
        return (*lookup)[mask];
    }
};

// Time:  O((b/2) * (n/(b/2)+1)^(b/2))
// Space: O((n/(b/2)+1)^(b/2))
// dp solution
class Solution2 {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> count(batchSize);
        for (const auto& i : groups) {
            ++count[i % size(count)];
        }
        int result = count[0];
        count[0] = 0;
        for (int i = 1; i <= size(count) / 2; ++i) {
            int pair_count = 2 * i != size(count) ? min(count[i], count[size(count) - i]) : count[i] / 2;
            result += pair_count;
            count[i] -= pair_count;
            count[size(count) - i] -= pair_count;
        }
        int max_mask = accumulate(cbegin(count), cend(count), 1,
                                  [](int total, int c) {
                                      return total * (c + 1);
                                  });
        vector<int> dp(max_mask);
        for (int mask = 0; mask < size(dp); ++mask) {
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
        return result + dp.back();
    }
};
