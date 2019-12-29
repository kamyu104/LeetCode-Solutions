// Time:  O(10!* n * l)
// Space: O(n * l)

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
        }
        reverse(result.begin(), result.end());
        unordered_map<char, int> lookup;
        unordered_set<int> used;
        return backtracking(words, result, 0, 0, 0, &lookup, &used);
    }

private:
    bool backtracking(const vector<string>& words, const string& result,
                      int i, int j, int carry,
                      unordered_map<char, int> *lookup,
                      unordered_set<int> *used) {
        if (j == result.length()) {
            return carry == 0;
        }

        if (i != words.size()) {
            if (j >= words[i].length() || lookup->count(words[i][j])) {
                return backtracking(words, result, i + 1, j, carry, lookup, used);
            }
            for (int val = 0; val < 10; ++val) {
                if (used->count(val) || (val == 0 && j == words[i].length() - 1)) {
                    continue;
                }
                (*lookup)[words[i][j]] = val;
                used->emplace(val);
                if (backtracking(words, result, i + 1, j, carry, lookup, used)) {
                    return true;
                }
                used->erase(val);
                lookup->erase(words[i][j]);
            }
            return false;
        }

        const auto& total = accumulate(words.cbegin(), words.cend(), carry,
                                       [&j, &lookup](const auto& x, const auto& y) {
                                           return (j < y.length()) ? x + (*lookup)[y[j]] : x;
                                       });
        carry = total / 10;
        int val = total % 10;
        if (lookup->count(result[j])) {
            return val == (*lookup)[result[j]] &&
                   backtracking(words, result, 0, j + 1, carry, lookup, used);
        }
        if (used->count(val) || (val == 0 && j == result.length() - 1)) {
            return false;
        }
        (*lookup)[result[j]] = val;
        used->emplace(val);
        if (backtracking(words, result, 0, j + 1, carry, lookup, used)) {
            return true;
        }
        used->erase(val);
        lookup->erase(result[j]);
        return false;
    }
};
