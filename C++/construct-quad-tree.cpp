// Time:  O(n)
// Space: O(h)

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return nullptr;
        }
        return dfs(grid, 0, 0, grid.size());
    }

private:
    Node* dfs(const vector<vector<int>>& grid,
                    int x, int y, int l) {
        if (l == 1) {
            return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        int half = l / 2;
        auto topLeftNode = dfs(grid, x, y, half);
        auto topRightNode = dfs(grid, x, y + half, half);
        auto bottomLeftNode = dfs(grid, x + half, y, half);
        auto bottomRightNode = dfs(grid, x + half, y + half, half);
        if (topLeftNode->isLeaf && topRightNode->isLeaf &&
            bottomLeftNode->isLeaf && bottomRightNode->isLeaf &&
            topLeftNode->val == topRightNode->val &&
            topRightNode->val == bottomLeftNode->val &&
            bottomLeftNode->val == bottomRightNode->val) {
            return new Node(topLeftNode->val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(true, false, topLeftNode, topRightNode, bottomLeftNode, bottomRightNode);
    }
};
