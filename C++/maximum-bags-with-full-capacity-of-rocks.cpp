// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for (int i = 0; i < size(capacity); ++i) {
            capacity[i] -= rocks[i];
        }
        sort(begin(capacity), end(capacity));
        for (int i = 0; i < size(capacity); ++i) {
            if (capacity[i] > additionalRocks) {
                return i;
            }
            additionalRocks -= capacity[i];
        }
        return size(capacity);
    }
};
