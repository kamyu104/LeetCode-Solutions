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

// Time:  O(nlogn)
// Space: O(n)
// prefix sum, binary search
class Solution2 {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        vector<int> prefix(size(tiles) + 1);
        for (int i = 0; i < size(tiles); ++i) {
            prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
        }
        int result = 0;
        for (int i = 0; i < size(tiles); ++i) {
            const int l = tiles[i][0];
            const int r = l + carpetLen - 1;
            const int j = distance(cbegin(tiles), upper_bound(cbegin(tiles), cend(tiles), vector<int>(1, r + 1)));
            const int extra = max(tiles[j - 1][1] - r, 0);
            result = max(result, (prefix[j] - prefix[i]) - extra);
        }
        return result;
    }
};
