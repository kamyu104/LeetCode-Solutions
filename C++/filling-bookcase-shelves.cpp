// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size() + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= books.size(); ++i) {
            int max_width = shelf_width;
            int max_height = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (max_width - books[j][0] < 0) {
                    break;
                }
                max_width -= books[j][0];
                max_height = max(max_height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + max_height);
            }
        }
        return dp[books.size()];
    }
};
