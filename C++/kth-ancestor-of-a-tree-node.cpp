// Time:  ctor: O(n * logh)
//        get:  O(logh)
// Space: O(n * logh)

// binary jump solution (frequently used in competitive programming)
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<int> q;
        for (const auto& p : parent) {
            parent_.emplace_back(vector<int>(p != -1, p));
            if (p != -1) {
                q.emplace_back(parent_.size() - 1);
            }
        }
        for (int i = 0; !q.empty(); ++i) {
            vector<int> new_q;
            for (const auto& curr : q) {
                if (!(i < parent_[parent_[curr][i]].size())) {
                    continue;
                }
                parent_[curr].emplace_back(parent_[parent_[curr][i]][i]);
                new_q.emplace_back(curr);
            }
            q = move(new_q);
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
