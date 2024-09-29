// Time:  O(n + m)
// Space: O(m)

// hash table, greedy
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> lookup(size(word2), -1);
        for (int i = size(word1) - 1, j = size(word2) - 1; i >= 0; --i) {
            if (word1[i] != word2[j]) {
                continue;
            }
            lookup[j--] = i;
            if (j == -1) {
                break;
            }
        }
        vector<int> result;
        for (int i = 0, cnt = 0; i < size(word1); ++i) {
            if (!(word1[i] == word2[size(result)] ||
                  (cnt == 0 && (size(result) + 1 == size(word2) || i < lookup[size(result) + 1])))) {
                continue;
            }
            if (word1[i] != word2[size(result)]) {
                ++cnt;
            }
            result.emplace_back(i);
            if (size(result) == size(word2)) {
                return result;
            }
        }
        return {};
    }
};
