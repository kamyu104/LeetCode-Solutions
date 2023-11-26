// Time:  O(n * l)
// Space: O(1)

// string
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < size(words); ++i) {
            if (find(cbegin(words[i]), cend(words[i]), x) != cend(words[i])) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
