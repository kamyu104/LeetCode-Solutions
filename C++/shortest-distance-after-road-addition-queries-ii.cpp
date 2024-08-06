// Time:  O(nlogn)
// Space: O(n)

// bst
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        set<int> bst;
        for (int i = 0; i < n; ++i) {
            bst.emplace(i);
        }
        for (const auto& q : queries) {
            auto jt = bst.lower_bound(q[1]);
            for (auto it = bst.upper_bound(q[0]); it != jt; it = bst.erase(it));
            result.emplace_back(size(bst) - 1);
        }
        return result;
    }
};
