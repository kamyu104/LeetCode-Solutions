// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        vector<int> prefix(size(possible) + 1);
        for (int i = 0; i < size(possible); ++i) {
            prefix[i + 1] = prefix[i] + (possible[i] ? +1 : -1);
        }
        for (int i = 0; i + 1 < size(possible); ++i) {
            if (prefix[i + 1] > prefix.back() - prefix[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};
