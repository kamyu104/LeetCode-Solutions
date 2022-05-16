// Time:  O(nlogn)
// Space: O(1)

// sliding window
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        int result = 0;
        for (int right = 0, left = 0, gap = 0; right < size(tiles); ++right) {
            if (right - 1 >= 0) {
                gap += (tiles[right][0] - 1) - tiles[right - 1][1];
            }
            result = max(result, min(tiles[right][1] - tiles[left][0] + 1, carpetLen) - gap);
            while (tiles[right][1] - tiles[left][0] + 1 > carpetLen) {
                ++left;
                gap -= (tiles[left][0] - 1) - tiles[left - 1][1];
                result = max(result, min(tiles[right][1] - tiles[left][0] + 1, carpetLen) - gap);
            }
        }
        return result;
    }
};
