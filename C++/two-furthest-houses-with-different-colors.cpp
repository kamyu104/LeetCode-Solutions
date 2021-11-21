// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int result = 0;
        for (int i = 0; i < size(colors); ++i) {
            if (colors[i] != colors[0]) {
                result = max(result, i - 0);
            }
            if (colors[i] != colors.back()) {
                result = max(result, static_cast<int>(size(colors)) - 1 - i);
            }
        }
        return result;
    }
};
