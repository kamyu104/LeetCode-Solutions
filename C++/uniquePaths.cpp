// Time Complexity: O(mn)
// Time Complexity: O(mn)

class Solution {
    public:
        unordered_map<int, unordered_map<int, int> > hash;
        int uniquePaths(int m, int n) {
            if(m == 0 || n == 0)
                return 0;
            if(m == 1 || n == 1)
                return 1;
            if(hash.find(m) != hash.end() && hash[m].find(n) != hash[m].end())
                return hash[m][n];
            return hash[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        }
};
