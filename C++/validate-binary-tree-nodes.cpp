// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> roots;
        for (int i = 0; i < n; ++i) {
            roots.emplace(i);
        }
        for (const auto& i : leftChild) {
            roots.erase(i);
        }
        for (const auto& i : rightChild) {
            roots.erase(i);
        }
        if (size(roots) != 1) {
            return false;
        }
        const auto& root = *cbegin(roots);
        vector<int> stk({root});
        unordered_set<int> lookup({root});
        while (!empty(stk)) {
            const auto node = stk.back(); stk.pop_back();
            for (const auto& i : {leftChild[node], rightChild[node]}) {
                if (i < 0) {
                    continue;
                }
                if (lookup.count(i)) {
                    return false;
                }
                lookup.emplace(i);
                stk.emplace_back(i);
            }
        }
        return size(lookup) == n;
    }
};
