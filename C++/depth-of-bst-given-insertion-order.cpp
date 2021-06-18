// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        map<int, int> depths = {{numeric_limits<int>::min(), 0},
                                {numeric_limits<int>::max(), 0}};
        int result = 0;
        for (const auto& x : order) {
            auto it = depths.upper_bound(x);
            depths[x] = max(prev(it)->second, it->second) + 1;
            result = max(result, depths[x]);
        }
        return result;
    }
};
