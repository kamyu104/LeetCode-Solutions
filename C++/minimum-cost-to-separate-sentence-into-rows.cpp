// Time:  O(s + n * k), n is the number of the word_lens
// Space: O(k)

class Solution {
public:
    int minimumCost(string sentence, int k) {
        vector<int> word_lens, dp;  // dp[i]: min cost of word_lens[-1-i:]
        for (int i = size(sentence) - 1, j = size(sentence) - 1, t = -1; i >= -1; --i) {
            if (i != -1 && sentence[i] != ' ') {
                continue;
            }
            const int l = j - i;
            j = i - 1;
            word_lens.emplace_back(l);
            dp.emplace_back(numeric_limits<int>::max());
            t += l + 1;
            if (t <= k) {
                dp.back() = 0;
                continue;
            }
            int total = l;
            for (int j = size(dp) - 2; j >= 0; --j) {
                dp.back() = min(dp.back(), dp[j] + (k - total) * (k - total));
                total += (word_lens[j] + 1);
                if (total > k) {
                    word_lens = vector<int>(cbegin(word_lens) + j, cend(word_lens));  // minimize len(word_lens) s.t. sum(word_lens) > k
                    dp = vector<int>(cbegin(dp) + j, cend(dp));
                    break;
                }
            }
        }
        return !empty(dp) ? dp.back() : 0;
    }
};

// Time:  O(s + n * k), n is the number of the word_lens
// Space: O(n)
class Solution2 {
public:
    int minimumCost(string sentence, int k) {
        vector<int> word_lens;
        for (int i = 0, j = 0; i <= size(sentence); ++i) {
            if (i != size(sentence) && sentence[i] != ' ') {
                continue;
            }
            word_lens.emplace_back(i - j);
            j = i + 1;
        }
        vector<int> dp(size(word_lens), numeric_limits<int>::max());  // dp[i]: min cost of word_lens[i:]
        int i = size(word_lens) - 1;
        for (int total = -1; i >= 0 && total + (word_lens[i] + 1) <= k; --i) {  // find max i s.t. the length of the last line > k
            total += (word_lens[i] + 1);
            dp[i] = 0;
        }
        for (; i >= 0; --i) {
            for (int j = i + 1, total = word_lens[i]; j < size(dp) && total <= k; total += (word_lens[j++] + 1)) {
                dp[i] = min(dp[i], dp[j] + (k - total) * (k - total));
            }
        }
        return dp[0];
    }
};

// Time:  O(s + n * k), n is the number of the word_lens
// Space: O(n)
class Solution3 {
public:
    int minimumCost(string sentence, int k) {
        vector<int> word_lens;
        for (int i = 0, j = 0; i <= size(sentence); ++i) {
            if (i != size(sentence) && sentence[i] != ' ') {
                continue;
            }
            word_lens.emplace_back(i - j);
            j = i + 1;
        }
        vector<int> dp(1 + (size(word_lens) - 1), numeric_limits<int>::max());  // dp[i]: min cost of the first i word_lens where i in [0, len(words)-1]
        dp[0] = 0;
        for (int i = 1; i <= (size(word_lens) - 1); ++i) {
            for (int j = i - 1, total = word_lens[i - 1]; j >= 0 && total <= k; --j) {
                dp[i] = min(dp[i], dp[j] + (k - total) * (k - total));
                if (j - 1 >= 0) {
                    total += (word_lens[j - 1] + 1);
                }
            }
        }
        int i = size(word_lens) - 1;
        for (int total = -1; i >= 0 && total + (word_lens[i] + 1) <= k; --i) {  // find max i s.t. the length of the last line > k
            total += (word_lens[i] + 1);
        }
        return *min_element(cbegin(dp) + (i + 1), cend(dp));
    }
};
