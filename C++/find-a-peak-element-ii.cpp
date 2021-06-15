// Time:  O(min(n, m) * log(max(n, m)))
// Space: O(1)

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = (max(size(mat), size(mat[0])) - 1) - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (check(mat, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        vector<int> result = {left, find_max(mat, left).first};
        if (!(size(mat) > size(mat[0]))) {
            reverse(begin(result), end(result));
        }
        return result;
    }

private:
    bool check(const vector<vector<int>>& mat, int x) {
        return find_max(mat, x).second > find_max(mat, x + 1).second;
    }
    
    pair<int, int> find_max(const vector<vector<int>>& mat, int x) {
        pair<int, int> result = {-1, -1};
        for (int j = 0; j < min(size(mat), size(mat[0])); ++j) {
            if (result.first == -1 || result.second < get_val(mat, x, j)) {
                result = {j, get_val(mat, x, j)};
            }
        }
        return result;
    }

    int get_val(const vector<vector<int>>& mat, int i, int j) {
        return (size(mat) > size(mat[0])) ? mat[i][j] : mat[j][i];
    }
};
