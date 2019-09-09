// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        if (width < height) {
            swap(width, height);
        }

        const auto& R = height / sideLength, &r = height % sideLength;
        const auto& C = width / sideLength, &c = width % sideLength;
        assert(R <= C);
        vector<pair<int, int>> area_counts = {{r * c, (R + 1) * (C + 1)},
                                              {r * (sideLength - c), (R + 1) * C},
                                              {(sideLength - r) * c, R * (C + 1)},
                                              {(sideLength - r) * (sideLength - c), R * C}};
        int result = 0;
        for (const auto& [area, count] : area_counts) {
            result += count * min(maxOnes, area);
            maxOnes -= min(maxOnes, area);
            if (!maxOnes) {
                break;
            }
        }
        return result;
    }
};
