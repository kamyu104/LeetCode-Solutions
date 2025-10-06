// Time:  O(n * l)
// Space: O(1)

// array
class Solution {
public:
    int maxDistance(vector<string>& words) {
        for (int i = 0; i <= size(words) / 2; ++i) {
            if (words[size(words) - 1 - i] != words[0] || words[i] != words.back()) {
                return size(words) - i;
            }
        }
        return 0;
    }
};
