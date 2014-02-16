// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        int candy(vector<int> &ratings) {
            const int n = ratings.size();
            vector<int> increment(n, 0);

            // left to right
            for(int i = 1, inc = 0; i < n; ++i) {
                if(ratings[i] > ratings[i - 1])
                    increment[i] = max(++inc, increment[i]);
                else
                    inc = 0;
            }

            // right to left
            for(int i = n - 2, inc = 0; i >= 0; --i) {
                if(ratings[i] > ratings[i + 1])
                    increment[i] = max(++inc, increment[i]);
                else
                    inc = 0;
            }

            return accumulate(increment.begin(), increment.end(), n);
        }
};
