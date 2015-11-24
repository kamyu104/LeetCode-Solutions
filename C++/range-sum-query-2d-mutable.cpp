// Time:  ctor:   O(m * n),
//        update: O(logm + logn),
//        query:  O(logm + logn)
// Space: O(m * n)

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) : matrix_ref_(matrix) {
        if (!matrix.empty() && !matrix[0].empty()) {
            const int m = matrix.size();
            const int n =  matrix[0].size();
            root_ = buildHelper(matrix,
                                make_pair(0, 0),
                                make_pair(m - 1, n - 1));
        }
    }

    void update(int row, int col, int val) {
        if (matrix_ref_[row][col] != val) {
            matrix_ref_[row][col] = val;
            updateHelper(root_, make_pair(row, col), val);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRangeHelper(root_, make_pair(row1, col1), make_pair(row2, col2));
    }

private:
    vector<vector<int>>& matrix_ref_;

    class SegmentTreeNode {
    public:
        pair<int, int> start, end;
        int sum;
        vector<SegmentTreeNode *> neighbor;
        SegmentTreeNode(const pair<int, int>& i, const pair<int, int>& j, int s) : 
            start(i), end(j), sum(s) {
        }
    };

    SegmentTreeNode *root_;

    // Build segment tree.
    SegmentTreeNode *buildHelper(const vector<vector<int>>& matrix,
                                 const pair<int, int>& start,
                                 const pair<int, int>& end) {
        if (start.first > end.first || start.second > end.second) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->sum = matrix[start.first][start.second];
            return root;
        }

        int mid_x = (start.first + end.first) / 2;
        int mid_y = (start.second + end.second) / 2;
        root->neighbor.emplace_back(buildHelper(matrix, start, make_pair(mid_x, mid_y)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(start.first, mid_y + 1), make_pair(mid_x, end.second)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(mid_x + 1, start.second), make_pair(end.first, mid_y)));
        root->neighbor.emplace_back(buildHelper(matrix, make_pair(mid_x + 1, mid_y + 1), end));
        for (auto& node : root->neighbor) {
            if (node) {
                root->sum += node->sum;
            }
        }
        return root;
    }

    void updateHelper(SegmentTreeNode *root, const pair<int, int>& i, int val) {
        // Out of range.
        if (root == nullptr ||
            (root->start.first > i.first || root->start.second > i.second) ||
            (root->end.first < i.first || root->end.second < i.second)) {
            return;
        }

        // Change the node's value with [i] to the new given value.
        if ((root->start.first == i.first && root->start.second == i.second) &&
            (root->end.first == i.first && root->end.second == i.second)) {
            root->sum = val;
            return;
        }
        for (auto& node : root->neighbor) {
            updateHelper(node, i, val);
        }

        root->sum = 0;
        for (auto& node : root->neighbor) {
            if (node) {
                root->sum += node->sum;
            }
        }
    }
    
    int sumRangeHelper(SegmentTreeNode *root, const pair<int, int>& start, const pair<int, int>& end) {
        // Out of range.
        if (root == nullptr ||
            (root->start.first > end.first || root->start.second > end.second) ||
            (root->end.first < start.first || root->end.second < start.second)) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if ((root->start.first >= start.first && root->start.second >= start.second) &&
            (root->end.first <= end.first && root->end.second <= end.second)) {
            return root->sum;
        }
        int sum = 0;
        for (auto& node : root->neighbor) {
            if (node) {
                sum += sumRangeHelper(node, start, end);
            }
        }
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
