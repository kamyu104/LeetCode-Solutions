// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {         
        int color = image[sr][sc];
        if (color == newColor) return image;
        dfs(&image, sr, sc, newColor, color);
        return image;
    }

private:
    void dfs(vector<vector<int>> *image, int r, int c, int newColor, int color) {
        static const vector<pair<int, int>> directions{{-1,  0}, { 1,  0},
                                                       { 0,  1}, { 0, -1}};
        if (r < 0 || r >= image->size() ||
            c < 0 || c >= (*image)[0].size() ||
            (*image)[r][c] != color) {
            return;
        }
        (*image)[r][c] = newColor;
        for (const auto& d : directions) {
            dfs(image, r + d.first, c + d.second, newColor, color);
        }
    }
};
