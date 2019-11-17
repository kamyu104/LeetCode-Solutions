// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        rotate(&grid, k);
        return grid;
    }

private:
    void rotate(vector<vector<int>> *grid, int k) {
        k %= grid->size() * (*grid)[0].size();
        reverse(grid, 0, grid->size() * (*grid)[0].size());
        reverse(grid, 0, k);
        reverse(grid, k, grid->size() * (*grid)[0].size());
    }
    
    void reverse(vector<vector<int>> *grid, int start, int end) {
        for (; start < end; ++start, --end) {
            int start_r = start / (*grid)[0].size();
            int start_c = start % (*grid)[0].size();
            int end_r = (end - 1) / (*grid)[0].size();
            int end_c = (end - 1) % (*grid)[0].size();
            swap((*grid)[start_r][start_c], (*grid)[end_r][end_c]);
        }
    }
};
