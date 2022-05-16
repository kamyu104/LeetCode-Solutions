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
// Space: O(1)
// sliding window
class Solution2 {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        int result = 0;
        for (int left = 0, right = 0, gap = 0; left < size(tiles); ++left) {
            if (left - 1 >= 0) {
                gap -= tiles[left][0] - tiles[left - 1][1] - 1;
            }
            const int r = tiles[left][0] + carpetLen - 1;
            while (right + 1 < size(tiles) && r + 1 >= tiles[right + 1][0]) {
                ++right;
                gap += tiles[right][0] - tiles[right - 1][1] - 1;
            }
            const int extra = max(tiles[right][1] - r, 0);
            result = max(result, ((tiles[right][1] - tiles[left][0] + 1) - gap) - extra);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// prefix sum, binary search
class Solution3 {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        vector<int> prefix(size(tiles) + 1);
        for (int i = 0; i < size(tiles); ++i) {
            prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
        }
        int result = 0;
        for (int left = 0; left < size(tiles); ++left) {
            const int r = tiles[left][0] + carpetLen - 1;
            const int right = distance(cbegin(tiles), prev(upper_bound(cbegin(tiles), cend(tiles), vector<int>(1, r + 1))));
            const int extra = max(tiles[right][1] - r, 0);
            result = max(result, (prefix[right + 1] - prefix[left]) - extra);
        }
        return result;
    }
};
