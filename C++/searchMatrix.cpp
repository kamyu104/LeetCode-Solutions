// Time Complexity: O(m+n)
// Time Complexity: O(log(mn))

class Solution {
    public:
        bool partitionAndSearch(vector<vector<int> > &matrix, int target, int i, int j, int m, int n) {
            if(m < 1 || n < 1)
                return false;
            int start, end;
            for(start = 0, end = min(m, n); start < end;) {
                int tmp = (start+end)/2;
                if(target < matrix[i+tmp][j+tmp])
                    end = tmp;
                else if (target > matrix[i+tmp][j+tmp])
                    start = tmp+1;
                else
                    return true;
            }
            if(start < 1)
                return false;
            return partitionAndSearch(matrix, target, i, j+start, m, n - start)
                || partitionAndSearch(matrix, target, i+start, j, m - start, n);
        }
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            return partitionAndSearch(matrix, target, 0, 0, matrix.size(), matrix[0].size());
        }
};
