// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < size(dist); ++i) {
            dist[i] = (dist[i] - 1) / speed[i];
        }
        sort(begin(dist), end(dist));
        int result = 0;
        for (; result < size(dist) && result <= dist[result]; ++result);
        return result;
    }
};
