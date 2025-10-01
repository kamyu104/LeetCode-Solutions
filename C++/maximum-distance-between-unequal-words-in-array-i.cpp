// Time:  O(n * l)
// Space: O(1)

// arry
class Solution {
public:
    int maxDistance(vector<string>& words) {
        if (words[0] != words.back()) {
            return (size(words) - 1) - 0 + 1;
        }
        int i = size(words) - 1;
        for (; i >= 0; --i) {
            if (words[i] != words[0]) {
                break;
            }
        }
        int j = 0;
        for (; j < size(words); ++j) {
            if (words[j] != words.back()) {
                break;
            }
        }
        return max(i - 0 + 1, (static_cast<int>(size(words)) - 1) - j + 1);
    }
};
