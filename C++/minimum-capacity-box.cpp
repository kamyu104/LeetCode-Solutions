// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        static const int INF = numeric_limits<int>::max();

        pair<int, int> result = {INF, -1};
        for (int i = 0; i < size(capacity); ++i) {
            if (capacity[i] >= itemSize) {
                result = min(result, pair(capacity[i], i));
            }
        }
        return result.second;
    }
};
