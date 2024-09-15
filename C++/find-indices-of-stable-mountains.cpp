// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;
        for (int i = 1; i < size(height); ++i) {
            if (height[i - 1] > threshold) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
