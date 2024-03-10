// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(rbegin(capacity), rend(capacity));
        for (int i = 0, total = accumulate(cbegin(apple), cend(apple), 0); i < size(capacity); ++i) {
            total -= capacity[i];
            if (total <= 0) {
                return i + 1;
            }
        }
        return -1;
    }
};
