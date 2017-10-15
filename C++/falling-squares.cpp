// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> heights(positions.size());
        for (int i = 0; i < positions.size(); ++i) {
            int left_i, size_i;
            tie(left_i, size_i) = positions[i];
            int right_i = left_i + size_i;
            heights[i] += size_i;
            for (int j = i + 1; j < positions.size(); ++j) {
                int left_j, size_j;
                tie(left_j, size_j) = positions[j];
                int right_j = left_j + size_j;
                if (left_j < right_i and left_i < right_j) {  // intersect
                    heights[j] = max(heights[j], heights[i]);
                }
            }
        }

        vector<int> result;
        for (const auto& height : heights) {
            result.emplace_back(result.empty() ? height : max(result.back(), height));
        }
        return result;
    }
};
