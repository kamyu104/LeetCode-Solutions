// Time:  ctor: O(n * logh)
//        get:  O(logh)
// Space: O(n * logh)

// binary jump solution (frequently seen in competitive programming)
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (const auto& p : parent) {
            parent_.emplace_back(vector<int>(p != -1, p));
        }
        for (int i = 0, max_depth = 1; i < max_depth; ++i) {
            for (auto& p : parent_) {
                if (!(i < p.size() && i < parent_[p[i]].size())) {
                    continue;
                }
                p.emplace_back(parent_[p[i]][i]);
                if (p.size() > max_depth) {
                    max_depth = p.size();
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (; k; k -= k & ~(k - 1)) {
            int i = __builtin_ctz(k & ~(k - 1));
            if (!(i < parent_[node].size())) {
                return -1;
            }
            node = parent_[node][i];
        }
        return node;
    }

private:
    vector<vector<int>> parent_;
};
