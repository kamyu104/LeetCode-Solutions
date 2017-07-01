// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int min_val = arrays[0].front(), max_val = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            result = max(result,
                         max(max_val - arrays[i].front(),
                             arrays[i].back() - min_val));
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }
        return result;
    }
};

