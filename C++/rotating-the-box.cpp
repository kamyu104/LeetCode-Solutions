// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> result(size(box[0]), vector<char>(size(box), '.'));
        for (int i = 0; i < size(box); ++i) {
            for (int j = size(box[0]) - 1, k = size(box[0]) - 1; j >= 0; --j) {
                if (box[i][j] == '.') {
                    continue;
                }
                if (box[i][j] == '*') {
                    k = j;
                }
                result[k--][size(box) -1 - i] = box[i][j];
            }
        }
        return result;
    }
};
