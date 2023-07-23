// Time:  O(n * l)
// Space: O(l)

// string
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        for (const auto& word : words) {
            for (int right = 0, left = 0; right <= size(word); ++right) {
                if (right != size(word) && word[right] != separator) {
                    continue;
                }
                if (right - left > 0) {
                    result.emplace_back(word.substr(left, right - left));
                }
                left = right + 1;
            }
        }
        return result;
    }
};
