// Time:  O(hlogh + wlogw)
// Space: O(1)

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        static const int MOD = 1e9 + 7;
        return max_len(h, &horizontalCuts) * max_len(w, &verticalCuts) % MOD;
    }

private:
    uint64_t max_len(int l, vector<int> *cuts) {
        sort(begin(*cuts), end(*cuts));
        l = max((*cuts)[0] - 0, l - cuts->back());
        for (int i = 1; i < cuts->size(); ++i) {
            l = max(l, (*cuts)[i] - (*cuts)[i - 1]);
        }
        return l;
    }
};
