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
        unordered_map<int, int> new_count;
        for (int i = 0; i < size(count); ++i) {
            if (count[i]) {
                new_count[i] = count[i];
            }
        }
        int max_mask = accumulate(cbegin(new_count), cend(new_count), 1,
                                  [](int total, pair<int, int> kvp) {
                                      return total * (kvp.second + 1);
                                  });
        vector<int> lookup(max_mask);
        return result + memoization(batchSize, new_count, max_mask - 1, 0, &lookup);
    }

private:
    int memoization(int batchSize, const unordered_map<int, int>& count, int mask, int remain, vector<int> *lookup) {
        if (!(*lookup)[mask]) {
            int a_remain = 0;
            int curr = mask, basis = 1;
            if (count.count(remain)) {
                for (const auto& [i, c] : count) {
                    if (i == remain) {
                        break;
                    }
                    basis *= (c + 1), curr /= (c + 1);
                }
                // mask: a0 + a1 * (c0 + 1)  + a2 * (c0 + 1) * (c1 + 1) + ... + a(b-1) * (c0 + 1) * (c1 + 1) * ... * (c(b-2) + 1)
                a_remain = curr % (count.at(remain) + 1);
            }
            int result = 0;
            if (a_remain) {  // greedily use remain
                result = max(result, (remain == 0) + memoization(batchSize, count, mask - basis, 0, lookup));
            } else {
                int curr = mask, basis = 1;
                for (const auto& [i, c] : count) {
                    if (curr % (c + 1)) {
                        result = max(result, (remain == 0) + memoization(batchSize, count, mask - basis, ((remain - i) + batchSize) % batchSize, lookup));
                    }
                    basis *= (c + 1), curr /= (c + 1);
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
        unordered_map<int, int> new_count;
        for (int i = 0; i < size(count); ++i) {
            if (count[i]) {
                new_count[i] = count[i];
            }
        }
        int max_mask = accumulate(cbegin(new_count), cend(new_count), 1,
                                  [](int total, pair<int, int> kvp) {
                                      return total * (kvp.second + 1);
                                  });
        vector<int> dp(max_mask);
        for (int mask = 0; mask < size(dp); ++mask) {
            int remain = 0;
            int curr = mask, basis = 1;
                for (const auto& [i, c] : new_count) {
                // mask: a0 + a1 * (c0 + 1)  + a2 * (c0 + 1) * (c1 + 1) + ... + a(b-1) * (c0 + 1) * (c1 + 1) * ... * (c(b-2) + 1)
                int ai = curr % (count[i] + 1);
                if (ai > 0) {
                    dp[mask] = max(dp[mask], dp[mask - basis]);
                }
                remain = (remain + ai * i) % batchSize;
                basis *= (c + 1), curr /= (c + 1);
            }
            if (mask != size(dp) - 1 && remain == 0) {
                ++dp[mask];
            }
        }
        return result + dp.back();
    }
};
