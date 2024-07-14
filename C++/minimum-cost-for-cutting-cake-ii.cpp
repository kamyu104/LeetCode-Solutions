// Time:  O(mlogm + nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(begin(horizontalCut), end(horizontalCut));
        sort(begin(verticalCut), end(verticalCut));
        int64_t result = 0;
        for (int cnt_h = 1, cnt_v = 1; !empty(horizontalCut) || !empty(verticalCut); ) {
            if (empty(verticalCut) || (!empty(horizontalCut) && horizontalCut.back() > verticalCut.back())) {
                result += horizontalCut.back() * cnt_h; horizontalCut.pop_back();
                ++cnt_v;
            } else {
                result += verticalCut.back() * cnt_v; verticalCut.pop_back();
                ++cnt_h;
            }
        }
        return result;
    }
};
