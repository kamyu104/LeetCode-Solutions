// Time:  O(nlogn)
// Space: O(n)

// bst
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        vector<int> arr(n);
        iota(begin(arr), end(arr), 0);
        set<int> bst(cbegin(arr), cend(arr));
        for (const auto& q : queries) {
            auto it = bst.upper_bound(q[0]);
            auto jt = bst.lower_bound(q[1]);
            for (; it != jt; it = bst.erase(it));
            result.emplace_back(size(bst) - 1);
        }
        return result;
    }
};
